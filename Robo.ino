#define echoPin1 A0 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin1 A1//attach pin D3 Arduino to pin Trig of HC-SR04

#define echoPin2 A2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin2 A3

#define echoPin3 A4 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin3 A5

#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
// defines variables
long duration, RightSensor, FrontSensor, LeftSensor; // variable for the duration of sound wave travel
int distance1, distance2, distance3, set = 20;// variable for the distance measurement

void setup()
{
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);


  //Set initial speed of the motor & stop

  // Serial.begin(9600);
  motor1.setSpeed(200); //
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
}

void UltraSensor(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance1 = (duration / 2) / 29.1;
  distance2 = (duration / 2) / 29.1;
  distance3 = (duration / 2) / 29.1;
  delay(0);
  
}
void loop(){
  UltraSensor(trigPin1, echoPin1);
  RightSensor = distance1;
  UltraSensor(trigPin2, echoPin2);
  FrontSensor = distance2;
  UltraSensor(trigPin3, echoPin3);
  LeftSensor = distance3;

  Serial.print(RightSensor);
  Serial.print(" - ");
  Serial.print(FrontSensor);
  Serial.print(" - ");
  Serial.println(LeftSensor);

  if (FrontSensor < 10)
  {
    motor1.run(FORWARD); //Code  for Right
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
    delay(500);
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    if (LeftSensor < 20 && RightSensor > 20)
    {
      motor1.run(FORWARD); //Code for Forward
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
      if (LeftSensor > 20 && RightSensor > 20)
      {
        motor1.run(BACKWARD);  //Code for Left
        motor2.run(BACKWARD);
        motor3.run(FORWARD);
        motor4.run(FORWARD);
        delay(500);
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        motor3.run(FORWARD);
        motor4.run(FORWARD);
        if (LeftSensor < 20 && RightSensor > 20)
        {
          motor1.run(FORWARD); //Code for Forward
          motor2.run(FORWARD);
          motor3.run(FORWARD);
          motor4.run(FORWARD);
          if (LeftSensor > 20 && RightSensor > 20)
          {
            motor1.run(BACKWARD);  //Code for Left
            motor2.run(BACKWARD);
            motor3.run(FORWARD);
            motor4.run(FORWARD);
            delay(500);
            motor1.run(FORWARD);
            motor2.run(FORWARD);
            motor3.run(FORWARD);
            motor4.run(FORWARD);
            if (LeftSensor < 20 && RightSensor > 20)
            {
              motor1.run(FORWARD); //Code for Forward
              motor2.run(FORWARD);
              motor3.run(FORWARD);
              motor4.run(FORWARD);
            }
          }
        }
      }
    }
  }

  else
  {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  }
}
