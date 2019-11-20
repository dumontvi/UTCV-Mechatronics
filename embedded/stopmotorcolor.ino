#include <Wire.h>
#include "Adafruit_TCS34725.h"

int ENA = 8;
int IN1 = 7;
int IN2 = 6;
//int i=0;
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
  while (1);
  }
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  float red, green, blue;
   tcs.setInterrupt(false);  // turn on LED
   delay(50);
  tcs.getRGB(&red,&green,&blue);
   tcs.setInterrupt(true);  // turn off LED

  Serial.print("R:\t"); Serial.print(int(red)); 
  Serial.print("\tG:\t"); Serial.print(int(green)); 
  Serial.print("\tB:\t"); Serial.println(int(blue));
  if (red>=220 && green>=20&& blue>=20){
    analogWrite(ENA,0);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    Serial.print("STOP");
    //delay(200);
  }else{
    analogWrite(ENA,255);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    //Serial.println(i);
    //delay(200);
  }
}
