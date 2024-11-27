/* for defining all used variables, libraries, etc.
*/
#include <ESP32_CAN.h>  // for CAN

#define baudSerial 115200  // baud rate for debug
#define serialDebug 1      // if 1, will Serial print
#define ChassisCANDebug 0  // if 1, will print CAN 1 (Chassis) messages

#define pinCAN_RX 14  // RX pin for SN65HVD230 (CAN_RX)
#define pinCAN_TX 13  // TX pin for SN65HVD230 (CAN_TX)

#define LH_Sense 36  // current sensing for the LH motor (input)
#define RH_Sense 39  // current sensing for the RH motor (input)

#define HB_Engage 16     // input to 'engage' the handbrake
#define HB_Disengage 17  //input to 'disengage' the handbrake
#define HB_Service 34    // input to 'service' the handbrake

#define HB_In 18   // LED for monitoring handbrake status
#define HB_Out 19  // LED for monitoring handbrake status

#define mot1_ena 21  // enable motor 1
#define mot1_in1 22  // motor 1 direction?
#define mot1_in2 23  // motor 1 direction?

#define mot2_ena 25  // enable motor 2
#define mot2_in1 26  // motor 2 direction?
#define mot2_in2 27  //motor 2 direction?

#define currentLimit 2000  // mA current limit for BOTH motors(!)
#define enaTimeLimit 5000  // timer override for motor engage limit

// CAN Addresses
#define MOTOR1_ID 0x280
#define MOTOR2_ID 0x288
#define MOTOR3_ID 0x380
#define BRAKES1_ID 0x1A0
#define BRAKES2_ID 0x2A0
#define BRAKES3_ID 0x4A0

extern byte vehicleSpeed = 0;
extern int vehicleRPM = 0;  // current RPM
extern int calcSpeed = 0;   // temp var for calculating speed
extern int serviceMode = 0;

extern int LH_current = 0;
extern int RH_current = 0;

extern uint16_t startMot = 0;

extern bool toggleMotorEngage = false;
extern bool toggleMotorDisengage = false;
