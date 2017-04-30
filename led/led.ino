#include <SerialCommand.h>

#include <SoftwareSerial.h>

#include <Servo.h>

  Servo TurnServo;
  Servo AccelerateServo;
  SerialCommand sCmd;
  
  int stopk = 86;
  int val;
  
  int accelerate = 16; //pin
  int turn = 10; //pin

void setup()
{
  Serial.begin(9600);
  
  AccelerateServo.attach(accelerate);
  TurnServo.attach(turn);
  
  AccelerateServo.write(90);// 90 stop  
  TurnServo.write(86);  
  
  sCmd.addCommand("r", Go);
  sCmd.addCommand("a", Ang);

  sCmd.addCommand("W", forward);
  sCmd.addCommand("D", TurnRight);
  sCmd.addCommand("A", TurnLeft);
  sCmd.addCommand("S", back );

//  sCmd.addDefaultHandler(unrecognized);
}

void loop()                    
{
  sCmd.readSerial();
}
void Go() {
  int speed_ = 0;
  int speed_val = 88; // 86 90

  char *arg;
  arg = sCmd.next();
  if (arg != NULL)      // As long as it existed, take it
  {
    Serial.println(arg);
    speed_ = atoi(arg);
    if (speed_ < 0) {
      speed_val = 90 - speed_;
    } else if (speed_ > 0) {
      speed_val = 86 - speed_;
    } else {
      speed_val = 88;
    }
  }

  AccelerateServo.write(speed_val);

}

void Ang() {
  int ang_ = 3;
  int ang_val = 84; //

  char *arg;
  arg = sCmd.next();
  if (arg != NULL)      // As long as it existed, take it
  {
    Serial.println(arg);
    ang_ = atoi(arg);
    ang_val = 84 - ang_;
  }

  TurnServo.write(ang_val);


}


void forward() {
  TurnServo.write(84);
  stopk++;
  Serial.println(stopk);
  AccelerateServo.write(stopk);

}
void back() {
  Serial.println("DOWN");
  TurnServo.write(92);
  stopk--;
  Serial.println(stopk);
  AccelerateServo.write(stopk);
}
void TurnLeft() {
  Serial.println("left");
  TurnServo.write(115);
  //AccelerateServo.write();
}
void TurnRight() {
  Serial.println("right");
  TurnServo.write(55);
  //AccelerateServo();
}

void Stop() {
  Serial.println("stop");
  AccelerateServo.write(75);
}
void unrecognized() {
  Serial.println("alredy");
}

