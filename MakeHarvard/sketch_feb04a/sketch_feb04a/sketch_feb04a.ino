int trigPinRight=4;
int echoPinRight=5;
int n=10;
int timeRight;
int distanceRight;
void setup() {
  // put your setup code here, to run once:
pinMode(echoPinRight,INPUT);
pinMode(trigPinRight,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(trigPinRight,HIGH);
  delayMicroseconds(n);
  digitalWrite(trigPinRight,LOW);
  timeRight=pulseIn(echoPinRight,HIGH);
  distanceRight=timeRight*.034/2;
  Serial.println(distanceRight);
  delay(50);
}
