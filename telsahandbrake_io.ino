void basicInit() {
// basic initialisation - setup pins for IO & setup CAN for receiving...
#if serialDebug
  Serial.begin(baudSerial);
  Serial.println(F("Electronic Parking Brake Controller Initialising..."));
  Serial.println(F("Setting up pins..."));
#endif
  setupPins();  // initialise the CAN chip
#if serialDebug
  Serial.println(F("Setup pins complete!"));
#endif

#if serialDebug
  Serial.println(F("CAN Chip enabling..."));
#endif
  canInit();  // initialise the CAN chip
#if serialDebug
  Serial.println(F("CAN Chip enabled!"));
#endif
}

void setupPins() {
  // define pin modes for IO
  pinMode(LH_Sense, INPUT);  // for current monitoring
  pinMode(RH_Sense, INPUT);  // for current monitoring

  attachInterrupt(digitalPinToInterrupt(HB_Engage), engage, HIGH);  // for interrupts, engage/disengage/service
  attachInterrupt(digitalPinToInterrupt(HB_Disengage), disengage, HIGH);
  attachInterrupt(digitalPinToInterrupt(HB_Service), service, HIGH);

  pinMode(HB_In, OUTPUT);   // for LED outputs
  pinMode(HB_Out, OUTPUT);  // for LED outputs

  pinMode(mot1_ena, OUTPUT);  // for motor 1 enable
  pinMode(mot1_in1, OUTPUT);  // for motor 1 direction
  pinMode(mot1_in2, OUTPUT);  // for motor 1 direction
  pinMode(mot2_ena, OUTPUT);  // for motor 2 enable
  pinMode(mot2_in1, OUTPUT);  // for motor 2 direction
  pinMode(mot2_in2, OUTPUT);  // for motor 2 direction
}


void engage() {
  toggleMotorEngage = true;
  startMot = millis();
}

void disengage() {
  toggleMotorDisengage = true;
  startMot = millis();
}

void service() {
  serviceMode++;
  if (serviceMode > 2) {
    serviceMode = 0;
  }
  startMot = millis();
}