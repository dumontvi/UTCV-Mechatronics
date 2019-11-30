#include <Adafruit_TCS34725.h>
#include <Wire.h>
<<<<<<< HEAD
=======
#include "Adafruit_TCS34725.h"
>>>>>>> 506052b9382d27b56a9c094249d4012c84f37207
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_60X);


// Definitions Arduino pins connected to input H Bridge
int ENA = 8;
int IN1 = 7;
int IN2 = 6;

void setup()
{
// Set the output pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
//Check if sensor found
  Serial.begin(9600);
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
  while (1);
  }

}

char rx_byte = 0; //holds input character
int start_time;
int end_time;
int duration;


int initr=0; //initial vals
int initg=0;
int initb=0;
int prevr=0; //previous vals
int prevg=0;
int prevb=0;
float red=0; //current vals
float green=0;
float blue=0;
int dprevr=0; //difference from previous vals
int dprevg=0;
int dprevb=0;

void loop()
{
  prevr=red; //current vals from prev cycle become prev vals
  prevg=green;
  prevb=blue;
  
  //color sensor
  delay(10); //poll every 10 ms
  tcs.getRGB(&red,&green,&blue); //update current vals

  //Serial.print("R:\t"); Serial.print(int(red)); 
  //Serial.print("\tG:\t"); Serial.print(int(green)); 
  //Serial.print("\tB:\t"); Serial.println(int(blue));

  //check input
  if (Serial.available() > 0) {
    rx_byte = Serial.read();
    if (rx_byte == 'a'){ //if a, turn on motor
      start_time = millis()/1000; //start timer
      Serial.print("start\t");
      Serial.println(start_time);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(ENA,255);
      initr = red; //set initial colour
      initg = green;
      initb = blue;
    }
  }
  
  dprevr = abs(red-prevr); //difference w/ prev vals
  dprevg = abs(green-prevg);
  dprevb = abs(blue-prevb);

<<<<<<< HEAD
  //if (abs(red-initr)!=0||abs(green-initg)!=0||abs(blue-initb)!=0){ //if at least one of current vals differ from initial
  Serial.print(dprevr); //print differences
  Serial.print(", "); 
  Serial.print(dprevg); 
  Serial.print(", "); 
  Serial.print(dprevb);
  Serial.print("\n");
  //}
  
  if (dprevr>10&&dprevr<200&&dprevg>10&&dprevg<200&&dprevb>10&&dprevb<200){ //when spike occurs (ignore initial spike when first turned on)
=======
  if (abs(red-initr)!=0||abs(green-initg)!=0||abs(blue-initb)!=0){ //if at least one of current vals differ from initial
    Serial.println(dprevr); 
    Serial.println(dprevg);  
    Serial.println(dprevb);
  }

  if (dprevr==0&&dprevg==0&&dprevb==0){ //if no change. maybe make this a range or increase time between updates
>>>>>>> 506052b9382d27b56a9c094249d4012c84f37207
    Serial.println("STOP");
    analogWrite(ENA,0); //stop motor
    end_time = millis()/1000; //stop timer
    duration = (end_time - start_time); //time elapsed
    Serial.print("end:\t");Serial.print(end_time);
    Serial.print("\tstart:\t");Serial.print(start_time);
    Serial.print("\tduration:\t");Serial.print(duration);
    while(1); //infinite loop, can implement in such a way that if 'a' is entered again, will restart. need to put all the code in a function and call it in a condition inside the while loop.
  }
<<<<<<< HEAD
  /*
  if (red>=93&&green<=92&&blue<=75){
=======
  
  /*if (red>=93&&green<=92&&blue<=75){
>>>>>>> 506052b9382d27b56a9c094249d4012c84f37207
    Serial.println("STOP THE MOTOR");
    analogWrite(ENA,0);
    end_time = millis();
    duration = (end_time - start_time)/1000;
    Serial.print("end:\t");Serial.print(end_time);
    Serial.print("\tstart:\t");Serial.print(start_time);
    Serial.print("\tduration:\t");Serial.print(duration);
    while(1);
  }*/
}
