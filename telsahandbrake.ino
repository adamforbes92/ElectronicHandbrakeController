/* 
Basic Electronic Handbrake Controller.  Listens to the interrupts on engage/disengage and operates the motor to suit
Monitors the current drawn and once hit the limit, stops the motor
Built-in button for servicing the handbrake

Forbes-Automotive, 2024
*/

#include "telsahandbrake_config.h"
#include <ESP32_CAN.h>  // for CAN
ESP32_CAN<RX_SIZE_256, TX_SIZE_16> chassisCAN;

void setup() {
  basicInit();  // basic init for setting up IO / CAN
}

void loop() {
  if (toggleMotorEngage) {  // check to see if the toggle has been set by the interrupt, then engage the motor (in _motor)
    engageHandbrake();      // engage the motors to engage the handbrake
  }
  if (toggleMotorDisengage) {  // check to see if the toggle has been set by the interrupt, then disengage the motor (in _motor)
    disengageHandbrake();      // disengage the motors to engage the handbrake
  }

  if (serviceMode == 1) {  // check to see if the 'service' button has been engaged and manually engage/disengage the handbrake
    engageHandbrake();
  }
  if (serviceMode == 2) {  // check to see if the 'service' button has been engaged and manually engage/disengage the handbrake
    disengageHandbrake();
  }
}
