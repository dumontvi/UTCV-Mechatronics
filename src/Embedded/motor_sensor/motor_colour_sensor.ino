#include <Wire.h>
#include "Adafruit_TCS34725.h"
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);


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

  Serial.begin(9600);
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
  while (1);
  }

}

void loop()
{

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  float red, green, blue;
  tcs.setInterrupt(false);  // turn on LED
  delay(50);
  tcs.getRGB(&red,&green,&blue);
  tcs.setInterrupt(true);  // turn off LED

  Serial.print("R:\t"); Serial.print(int(red)); 
  Serial.print("\tG:\t"); Serial.print(int(green)); 
  Serial.print("\tB:\t"); Serial.println(int(blue));
  
  if ((red>=200||red>=240)&&(green>=18||green<=35)&&(blue>=23||blue<=38)){
    Serial.println("STOP THE MOTOR");
    analogWrite(ENA,0);
    delay(100);
  }
  else {
    analogWrite(ENA,200);
    delay(50);
  }
}
