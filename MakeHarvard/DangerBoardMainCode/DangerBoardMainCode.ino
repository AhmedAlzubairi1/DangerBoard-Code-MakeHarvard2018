#include "led.h"
bool motion=false;
bool accelometerIsWorking=false;
color_t blue;
  
color_t green;
int motionPin=13;
int trigPinForwardUp=2;
int echoPinForwardUp=3;
int trigPinForwardDown=4;
int echoPinForwardDown=5;
int trigPinLeft=6;
int echoPinLeft=7;
int trigPinRight=8;
int echoPinRight=9; 
//pin 10-13 is used, 11 is for LEDs
//A5 and A6 is for accelometer
int n=10;

double timeForwardUp;
double distanceForwardUp=-1;
double timeForwardDown;
double distanceForwardDown=-1;
double timeLeft;
double distanceLeft=-1;
double timeRight;
double distanceRight=-1;

bool dangerZoneLeft=false;
bool dangerZoneRight=false;
bool dangerZoneForward=false;
void setup() {
  Serial.begin(9600);
pinMode(trigPinForwardUp,OUTPUT);
pinMode(trigPinForwardDown,OUTPUT);
pinMode(trigPinLeft,OUTPUT);
pinMode(trigPinRight,OUTPUT);
pinMode(echoPinForwardUp,INPUT);
pinMode(echoPinForwardDown,INPUT);
pinMode(echoPinLeft,INPUT);
pinMode(echoPinRight,INPUT);
pinMode(motionPin,INPUT);

led_setup();

  blue.red = 0x00;
  blue.green=0x00;
  blue.blue = 0xFF;
  green.red=0x00;
  green.green=0xFF;
  green.blue=0x00;
}

void loop() {
//  set_color_left(green);
 // set_color_right(green);
//  set_color_center(green);
/*
  //LED Flash test
  flash_red_left(10);
 // delay(1000);
   // set_color_left(blue);

  
  //7805 power regulator 
  //red is 9 v and black is g
  //red is power, yellow is ground
  //input ground output
  */
  //Changeto true
  //  if(motionPin==HIGH){

  if(digitalRead(motionPin)){
    accelometerIsWorking=true;
    Serial.println(digitalRead(motionPin));
  }
  else{
    accelometerIsWorking=false;
 //   Serial.println(digitalRead(motionPin));

  }
 if(accelometerIsWorking){
    motion=true;
  }
  else{
    motion=false;
  }
  
  //****Reset trig outputs
  digitalWrite(trigPinForwardUp,LOW);
  digitalWrite(trigPinForwardDown,LOW);
  digitalWrite(trigPinLeft,LOW);
  digitalWrite(trigPinRight,LOW);
  delayMicroseconds(2);
 

  
  //*****Initiate Forward Sensors 
  digitalWrite(trigPinForwardUp,HIGH);
  delayMicroseconds(n);
  digitalWrite(trigPinForwardUp,LOW);
  timeForwardUp=pulseIn(echoPinForwardUp,HIGH);
  distanceForwardUp=timeForwardUp*.034/2;
   if(distanceForwardUp<0){
    distanceForwardUp=-1;
  }
  if(distanceForwardUp>70 && distanceForwardUp<6){
    distanceForwardUp=-1;
  }
  //Make it accurate within 2 feet for now. Need to get something more accurate than an ultrasonic
  //*****************
  digitalWrite(trigPinForwardDown,HIGH);
  delayMicroseconds(n);
  digitalWrite(trigPinForwardDown,LOW);
  timeForwardDown=pulseIn(echoPinForwardDown,HIGH);
  distanceForwardDown=timeForwardDown*.034/2;

  /*
  if(distanceForwardDown<0){
    distanceForwardDown=-1;
  }
  if(distanceForwardDown>70 && distanceForwardDown<6){
    distanceForwardDown=-1;
    dangerZoneForward=true;
  }
  if(distanceForwardUp<0 || distanceForwardDown<0){
    dangerZoneForward=false;

  }
 /* else{
    dangerZoneForward=true;
  }
  */
  

   if(distanceForwardUp<0){
    distanceForwardUp=-1;
  }
  
  if(distanceForwardUp>70 || distanceForwardUp<6){
    distanceForwardUp=-1;
  }

  if(distanceForwardUp==-1){
    dangerZoneForward=false;
  }
  else{
    dangerZoneForward=true;
  }

  //*******************************


  //******Initate Left Sensors
  digitalWrite(trigPinLeft,HIGH);
  delayMicroseconds(n);
  digitalWrite(trigPinLeft,LOW);
  timeLeft=pulseIn(echoPinLeft,HIGH);
  distanceLeft=timeLeft*.034/2;
  if(distanceLeft<0){
    distanceLeft=-1;
  }
  
  if(distanceLeft>70 || distanceLeft<6){
    distanceLeft=-1;
  }

  if(distanceLeft==-1){
    dangerZoneLeft=false;
  }
  else{
    dangerZoneLeft=true;
  }
  //**************


  //******Initate Right Sensors
  digitalWrite(trigPinRight,HIGH);
  delayMicroseconds(n);
  digitalWrite(trigPinRight,LOW);
  timeRight=pulseIn(echoPinRight,HIGH);
  distanceRight=timeRight*.034/2;
  if(distanceRight<0){
    distanceRight=-1;
  }
  if(distanceRight>70 && distanceRight<6){
    distanceRight=-1;
  }
  if(distanceRight==-1){
    dangerZoneRight=false;
  }
  else{
    dangerZoneRight=true;
  }



  //***********
if(dangerZoneRight==true){
  //blinkRight

  flash_red_right(10);
  

  dangerZoneRight=false;
}
else{
  if(motion){
    //be in motion
    
    set_color_right(green);
  }
  else{
    //not in motion
    set_color_right(blue);
  }
}

//else turn off
if(dangerZoneForward==true){
  //blinkForward
  flash_red_center(10);
  dangerZoneForward=false;

}
else{
  if(motion){
    //be in motion
    set_color_center(green);
  }
  else{
    //not in motion
    set_color_center(blue);
  }
}
if(dangerZoneLeft==true){
  //blink left
  flash_red_left(10);
     //   delay(1000);


  dangerZoneLeft=false;
}
else{
  if(motion){
    //be in motion

    set_color_left(green);
  }
  else{
    //not in motion
    set_color_left(blue);
  }
}

}
