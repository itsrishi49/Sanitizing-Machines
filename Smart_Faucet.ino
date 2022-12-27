#define trig 5
#define echo 4
const int Relay = 6;
long duration;
int distance;
void setup() {
  pinMode(trig, OUTPUT); // Set the trigger pin as OUTPUT
  pinMode(echo, INPUT); // Set the echo pin as INPUT
  pinMode(Relay, OUTPUT); // Configure the pin of the relay module as OUTPUT
  Serial.begin(9600); // Set baud rate as 9600
}
void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH); // Calculate time taken (in microseconds) for the pulse emitted by the trigger pin to reach the echo pin.
  distance = (duration/2) * (331.3/10000); // Calculate the distance from the sensor to the obstacle in cm, using the speed of sound in air(m/s) and the time taken (stored in duration variable)
  Serial.println(distance);
  if(distance>1 && distance<10){ 
    digitalWrite(Relay, HIGH); //Turns on the submersible water pump based on your NO & NC in Relay
  }else{
    digitalWrite(Relay, LOW); //Turns off the submersible water pump based on your NO & NC in Relay
   }
   delay(2000); // Set a delay period of 2 seconds to prevent the clicking of the relay module
}
