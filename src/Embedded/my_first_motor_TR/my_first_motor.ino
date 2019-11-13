//NOTE: ground of motor and ground of arduino should be the same 
// NOTE: both the grounds connect to negative terminal of the battery & the positive of the battery connects to the motor controller 
int enA = 10;// defining variables 
int in1 = 9;
int in2 = 8;
int i = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(enA, OUTPUT); //setting pins to input or output (arduino pins)
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  analogWrite(enA, 200); //setting the motor to start running at speed 200(range from 0-255)
  digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH); 
}

void loop() {
  // put your main code here, to run repeatedly:
  i = i % 255; //setting speed to be between 0 to 255
  i = i+2; // increasing speed 
  
  Serial.println(i); //printing speed to serial monitor 
  
  digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH); 
  analogWrite(enA, i); //setting the motor to run at speed i
  delay(500); // delay the code half a second 
}
