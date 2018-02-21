int trigPinRight=9;
int echoPinRight=10;
int n =10;
int timeRight;
int distanceRight;
void setup() {
  // put your setup code here, to run once:
pinMode(trigPinRight,OUTPUT);
pinMode(echoPinRight,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:


  digitalWrite(trigPinRight,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinRight,HIGH);
  delayMicroseconds(n);
  digitalWrite(trigPinRight,LOW);
  timeRight=pulseIn(echoPinRight,HIGH);
  distanceRight=timeRight*.034/2;
  Serial.println(distanceRight);
  delay(1000);
}
