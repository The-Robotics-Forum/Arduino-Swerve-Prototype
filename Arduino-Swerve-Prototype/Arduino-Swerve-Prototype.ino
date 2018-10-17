/*
 * PrototypeSwerveDrive.ino
 * Created: 17-10-2018 23:00:00
 * //TODO:  1. Include servo.h
 *    2. Attach 2 servos on same pin
 *    3. Control angle using Android App
 *    4. Decapsulate data that is coming through Bluetooth
 */ 

/*************INDEX******************
* BUG – a known bug that should be corrected.
* FIXME – should be corrected.
* HACK – a workaround.
* TODO – something to be done.
* UNDONE – a reversal or "roll back" of previous code.
* XXX – warn other programmers of problematic or misguiding code
**************************************/


#include<Servo.h>
Servo swerve1;
Servo swerve2;
Servo swerve3;
Servo swerve4;
/********************VARIABLES***********************/
char recdChar;
int angle1=90;
uint8_t i=0;
bool start=0;   //flag variable for starting decapsulation of data
/******************Function Declarations***************/
void getAngle(); 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial3.begin(9600);
swerve1.attach(9);
swerve2.attach(10);
swerve1.attach(11);
swerve2.attach(6);

swerve1.write(90);
swerve2.write(90);
swerve3.write(90);
swerve4.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
  //getAngle();
  if(Serial3.available()){
    recdChar=Serial3.read();
    switch(recdChar){
      case 'A':
      angle1=0;
      break;
      case 'B':
      angle1=15;
      break;
      case 'C':
      angle1=30;
      break;
      case 'D':
      angle1=45;
      break;
      case 'E':
      angle1=60;
      break;
      case 'F':
      angle1=75;
      break;
      case 'G':
      angle1=90;
      break;
      case 'H':
      angle1=105;
      break;
      case 'I':
      angle1=120;
      break;
      case 'J':
      angle1=135;
      break;
      case 'K':
      angle1=150;
      break;
      case 'L':
      angle1=165;
      break;
      case 'M':
      angle1=180;
      break;
      default:
      angle1=90;
      break;
    }
    Serial.println(angle1);
  }
  swerve1.write(angle1);
  swerve2.write(angle1);
  swerve3.write(angle1);
  swerve4.write(angle1);
}

/*void getAngle(){
  while(Serial3.available()){
    recdChar=Serial3.read();    //read all incoming values
    if(recdChar=='['){    //encapsulation start charecter is recd
      start=1;    //start decapsulation
      i=0;  //restart counting for array
    }
    else if(recdChar==']'){
      start=0;
      //Serial.println(angle);
    }
    else if(i<=2){
      angle[i]=recdChar;    //store decapsulated value in array
      i++;
    }
  }
}
*/
