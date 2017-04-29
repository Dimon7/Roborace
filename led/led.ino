#include <Servo.h>

Servo TurnServo;
Servo AccelerateServo;
int val;

boolean flag = false;
void setup()
{
  Serial.begin(9600);

  pinMode(16, OUTPUT);

  AccelerateServo.attach(16);
  AccelerateServo.write(100);// 90 stop  

  TurnServo.attach(10);//angle
  TurnServo.write(86);  
}

void loop()                    
{
  //  digitalWrite(16, HIGH);
  //  if(!flag){
  //  
  //    TurnServo.attach(10);//angle 
  //    val = 135;
  //    TurnServo.write(val); //Move the servo (0 degree)
  //    delay(2000);
  //    TurnServo.detach();
  //    flag = true;
  //  }


  //  switch( Serial.read() ){
  //    
  //    case 'r' : { 
  //                //right(); 
  //                servo.write(55);
  //                break;
  //    }
  //    case 'l' : { 
  //                //left();
  //                servo.write(115);
  //                break;  
  //    }
  //    case 'o' : { 
  ////                none(); 
  //              servo.write(86);
  //                break;
  //    }
  //      


  //
  //  void none(){
  //
  //    servo.write(86);  
  //  }
  //  void left(){
  //      servo.write(115);  
  //  }
  //
  //  void right(){
  //    servo.write(55);
  //    
  //  }



}

