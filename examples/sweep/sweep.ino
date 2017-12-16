// this example illustrates the basic usage of the library
// the minimal standard Servo library methods are used here to have a servo
// sweep back and forth

#include <ESP32Servo.h>

#define SERVO_PIN 5

// using alternative constructor here, passing the pin
ESP32Servo servo(SERVO_PIN);

void setup() {
  Serial.begin(115200);

	// this is not needed due to the use of the alternative constructor above
  // servo.attach(SERVO_PIN);

  servo.write(0);
  delay(3000);
  servo.write(90);
  delay(3000);
  servo.write(180);
  delay(3000);
  servo.write(0);
  delay(3000);
}

void loop() {
  for(int i=0; i<180 ; i+=5) {
    servo.write(i);
    Serial.print(servo.read());
    Serial.print(" = ");
    Serial.println(servo.readMicroseconds());
    delay(150);
  }
  for(int i=180; i>0 ; i-=5) {
    servo.write(i);
    Serial.print(servo.read());
    Serial.print(" = ");
    Serial.println(servo.readMicroseconds());
    delay(150);
  }
}
