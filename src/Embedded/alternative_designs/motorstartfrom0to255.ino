// Definitions Arduino pins connected to input H Bridge
int ENA = 8;
int IN1 = 7;
int IN2 = 6;
int i=0;
void setup()
{
// Set the output pins
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(ENA, OUTPUT);
Serial.begin(9600);
}

void loop()
{
i++;
analogWrite(ENA,i);
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
Serial.println(i);
delay(200);
}
