/*
 * PrototypeSwerveDrive.cpp
 * Created: 16-10-2018 18:48:07
 * Updated: 16-10-18 19:59  
 * //TODO:  1. Include servo.h
      2. Attach 2 servos on same pin
      3. Control angle using Android App
 */ 
/*************INDEX******************
*BUG – a known bug that should be corrected.
*FIXME – should be corrected.
*HACK – a workaround.
*TODO – something to be done.
*UNDONE – a reversal or "roll back" of previous code.
*XXX – warn other programmers of problematic or misguiding code
*/
#include<Servo.h>
#define trig 22
#define echo 3
   
float k=0.12;  // Constant for getting the sine wave
int ang1=90,ang2=90,ang3=90,ang4=90;  //Initial angles of servo motors for all wheels to be parallel
int v,y,z,w;   //Angles of servo
int dist;   //Distance in mm from wall

Servo p;   // 4 Objects created for 4 servos
Servo q;
Servo r;
Servo s;
  void angle1(int dist)
  {
    v=(ang1-90) +(dist-1250)*k;
    y=(ang2-90)+ (dist-1250)*k;
    z=(ang3-90)+ (dist-1250)*k;
    w=(ang4-90)+ (dist-1250)*k;

    p.write(v);
    q.write(y);
    r.write(z);
    s.write(w);
  }
  void angle2(int dist)
  {
    v=ang1 + (dist-2000)*k;
    y=ang2 + (dist-2000)*k;
    z=ang3 + (dist-2000)*k;
    w=ang4 + (dist-2000)*k;

    p.write(v);
    q.write(y);
    r.write(z);
    s.write(w);
  }
  void angle3(int dist)
  {
    v=(ang1+90)-(dist-2750)*k;
    y=(ang2+90)-(dist-2750)*k;
    z=(ang3+90)-(dist-2750)*k;
    w=(ang4+90)-(dist-2750)*k;

    p.write(v);
    q.write(y);
    r.write(z);
    s.write(w);
    
  }
  void angle4(int dist)
  {
    v=ang1-(dist-500)*k;
    y=ang2-(dist-500)*k;
    z=ang3-(dist-500)*k;
    w=ang4-(dist-500)*k;
    
    p.write(v);
    q.write(y);
    r.write(z);
    s.write(w);
    
  }
  void angle5(int dist)
  {
    v=ang1-(dist-3500)*k;
    y=ang2-(dist-3500)*k;
    z=ang3-(dist-3500)*k;
    w=ang4-(dist-3500)*k;

    p.write(v);
    q.write(y);
    r.write(z);
    s.write(w);
    
  }
  void angle6(int dist)
  {
    v=(ang1-90)+ (dist-4250)*k;
    y=(ang2-90)+ (dist-4250)*k;
    z=(ang3-90)+ (dist-4250)*k;
    w=(ang4-90)+ (dist-4250)*k;

    p.write(v);
    q.write(y);
    r.write(z);
    s.write(w);
  }
  void angle7(int dist)
  {
    v=ang1+(dist-5000)*k;
    y=ang2+(dist-5000)*k;
    z=ang3+(dist-5000)*k;
    w=ang3+(dist-5000)*k;

    p.write(v);
    q.write(y);
    r.write(z);
    s.write(w);
    
  }




void setup(){
        pinMode(echo,0);
    pinMode(trig,1);
    p.attach(11);
    q.attach(12);
    r.attach(5);
    s.attach(3);
}
  
     void loop()
     {
       
      
    
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    
    //Distance is calculated in cm using US sensor
    int dur,distance;
    dur=pulseIn(echo,HIGH);
    Serial.println(dur);
    
    distance=0.034*dur/2;
    dist=distance*100; // Distance is converted in mm and stored in 'val' variable
    //According to the distance,we will decide in which quarter of the sine wave we should enter.
    
    if((500<=dist)&&(dist<=1250))
    {
      angle4(dist);
      
      
    }
    else if((1250<dist)&&(dist<=2000))
    {
      angle1(dist);
    }
    else if((2000<dist)&&(dist<=2750))
    {
      angle2(dist);
    }
    else if((2750<dist)&&(dist<=3500))
    {
      angle3(dist);
    }
    else if((3500<dist)&&(dist<=4250))
    {
      angle5(dist);
    }
    else if((4250<dist)&&(dist<=5000))
    {
      angle6(dist);
      
    }
    else if((5000<dist)&&(dist<=5750))
    {
      angle7(dist);
    }
  }
