/*
 * PrototypeSwerveDrive.ino
 * Created: 17-10-2018 23:00:00
 * //TODO:  1. Include servo.h
 *    2. Attach 2 servos on same pin
 *    3. Control angle using Android App
 */ 

/*************INDEX******************
* BUG – a known bug that should be corrected.
* FIXME – should be corrected.
* HACK – a workaround.
* TODO – something to be done.
* UNDONE – a reversal or "roll back" of previous code.
* XXX – warn other programmers of problematic or misguiding code
**************************************/
/********************VARIABLES***********************/
int recdAngle; 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial3.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial3.available()){
    recdAngle=Serial3.read();
    Serial.println(recdAngle);
  }
}
