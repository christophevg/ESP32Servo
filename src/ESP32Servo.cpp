#include "Arduino.h"
#include "ESP32Servo.h"

int ESP32Servo::next_channel = 0;

ESP32Servo::ESP32Servo() {
  // get next channel index and setup the channel
  ledcSetup(this->channel, this->frequency, this->resolution);
  this->channel = ESP32Servo::next_channel;
  ESP32Servo::next_channel++;
  ledcSetup(this->channel, this->frequency, this->resolution);
}

void ESP32Servo::attach(int pin) {
  this->pin = pin;
  ledcAttachPin(this->pin, this->channel);
  this->is_attached = true;
}

void ESP32Servo::attach(int pin, int min, int max) {
  this->min = min;
  this->max = max;
  this->attach(pin);
}

void ESP32Servo::write(int angle) {
  this->angle = angle;
  int us = map(this->angle, 0, 180, this->min, this->max);
  this->writeMicroseconds(us);
}

void ESP32Servo::writeMicroseconds(int us) {
  ledcWrite(this->channel, us);
}

int ESP32Servo::read() {
  return this->angle;
}

bool ESP32Servo::attached() {
  return this->is_attached;
}

void ESP32Servo::detach() {
  ledcDetachPin(this->pin);
  this->is_attached = false;
}

void ESP32Servo::write(int angle, int interval) {
  int step = angle < this->angle ? -1 : 1;
  while(this->angle != angle) {
    this->write(this->angle + step);
    delay(interval);
  }
}

int ESP32Servo::readMicroseconds() {
  return map(this->angle, 0, 180, this->min, this->max);
}

ESP32Servo::ESP32Servo(int pin) : ESP32Servo() {
	this->attach(pin);
}

void ESP32Servo::turn(int angle) {
	this->write(this->read() + angle);
}

void ESP32Servo::turn(int angle, int delay) {
	this->write(this->read() + angle, delay);	
}

void ESP32Servo::turn_to(int angle) {
	this->write(angle);	
}

void ESP32Servo::turn_to(int angle, int delay) {
	this->write(angle, delay);
}
