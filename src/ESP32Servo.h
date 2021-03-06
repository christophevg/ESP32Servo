#ifndef __ESP32SERVO_H
#define __ESP32SERVO_H

#include "Arduino.h"

class ESP32Servo {
  public:
    // implementation of the standard Arduino Servo API
    ESP32Servo();
    void attach(int pin);
    void attach(int pin, int min, int max);
    void write(int angle);
    void writeMicroseconds(int us);
    int  read();
    bool attached();
    void detach();
    // a few extensions:
		// - provide pin at construction, implies attaching the pin
		ESP32Servo(int pin);
    // - allow for changing the min/max settings
    // these defaults are determined manually for a Tower Pro MG 996R
    int min                 = 2500;
    int max                 = 7700;
    // - allow for moving to a new angle with a delay in between steps
    void write(int angle, int delay);
    // - read the current angle in microseconds
    int readMicroseconds();
		// - turn a given agle starting from the current position, opt. with delay
		void turn(int angle);
		void turn(int angle, int delay);
		// - alternative name for write method, opt. with delay
		void turn_to(int angle);
		void turn_to(int angle, int delay);
  protected:
    int resolution          =   16;
    int frequency           =   50;
    int channel             =    0;
    int pin                 =    0;
    int angle               =    0;
    bool is_attached        = false;
    static int next_channel;
};

#endif
