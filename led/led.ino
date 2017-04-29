#include <Servo.h>



Servo servo;

 
void setup()
{
  Serial.begin(9600);
      

  servo.attach(10);

  servo.write(86);  
}

void loop()                    
{
  
  switch( Serial.read() ){
    
    case 'r' : { 
                //right(); 
                servo.write(55);
                break;
    }
    case 'l' : { 
                //left();
                servo.write(115);
                break;  
    }
    case 'o' : { 
//                none(); 
              servo.write(86);
                break;
    }
      
  }

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
