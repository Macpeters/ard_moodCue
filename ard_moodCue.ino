#include <Servo.h>

Servo myServo;
int const potPin = A0;
int potVal;
int angle;

void setup() {
//  which pin the servo motor is connected to
  myServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);

// scale potVal value between 0 and 1023 to between 0 and 179
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);

  //move the servo motor
  myServo.write(angle);
  delay(15);
}
