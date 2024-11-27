bool engageHandbrake() {
  LH_current = analogRead(LH_Sense);  // monitor the current being drawn on both motors
  RH_current = analogRead(RH_Sense);  // monitor the current being drawn on both motors

  // if the motor has been running for less than the timeout, not overcurrent etc, let it be enabled.  If it's over ANY feature, disable the motor...
  if (millis() - startMot < enaTimeLimit && LH_current < currentLimit && RH_current < currentLimit) {
    digitalWrite(mot1_ena, HIGH);  // could use PWM for speed / ramp up?  Excessive?
    digitalWrite(mot2_ena, HIGH);  // could use PWM for speed / ramp up?  Excessive?
    digitalWrite(HB_In, HIGH);     // turn the LED off.  Possible flash it?
  } else {
    digitalWrite(mot1_ena, LOW);  // disable motor1, we're over a threshold...
    digitalWrite(mot2_ena, LOW);  // disable  motor2, we're over a threshold...
    digitalWrite(HB_In, LOW);     // turn the LED off.  Possible flash it?
  }

  // it doesn't matter if the motor is instructed to operate here, the 'ena' pin controls it...
  digitalWrite(mot1_in1, HIGH);
  digitalWrite(mot1_in2, LOW);
  digitalWrite(mot2_in1, HIGH);
  digitalWrite(mot2_in2, LOW);
}

bool disengageHandbrake() {
  LH_current = analogRead(LH_Sense);
  RH_current = analogRead(RH_Sense);

  if (millis() - startMot < enaTimeLimit && LH_current < currentLimit && RH_current < currentLimit) {
    digitalWrite(mot1_ena, HIGH);  // could use PWM for speed / ramp up?  Excessive?
    digitalWrite(mot2_ena, HIGH);  // could use PWM for speed / ramp up?  Excessive?
    digitalWrite(HB_Out, HIGH);
  } else {
    digitalWrite(mot1_ena, LOW);
    digitalWrite(mot2_ena, LOW);
    digitalWrite(HB_Out, LOW);
  }

  // it doesn't matter if the motor is instructed to operate here, the 'ena' pin controls it...
  digitalWrite(mot1_in1, LOW);
  digitalWrite(mot1_in2, HIGH);
  digitalWrite(mot2_in1, LOW);
  digitalWrite(mot2_in2, HIGH);
}