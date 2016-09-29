#include<Servo.h>

Servo esc;



void setup() {
  esc.attach(8);
  esc.writeMicroseconds(1000);
  Serial.begin(9600);
}

void loop() {
  int val;
  val=analogRead(A0);
  val= map(val, 0, 1023,1000,2000);
  esc.writeMicroseconds(val);
}
