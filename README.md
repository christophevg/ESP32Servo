# ESP32 Servo

An Arduino library to control a servo using the ESP32

## Installation

This folder should go in your Sketchbook/libraries folder. You can do this
using a symbolic link. E.g. on a Mac:

```bash
$ git clone https://github.com/christophevg/ESP32Servo
$ ln -s `pwd`/ESP32Servo ~/Documents/Arduino/libraries/
```

## Servo

This library is configured with defaults that match a Tower Pro MG996R servo. The `min` and `max` boundaries for the pulses can (and will) vary between servos. Current boundaries are 2500 and 7700 and were determined manually without going in too much detail ;-)

## API

The API mimiks the standard [Arduino Servo API](https://www.arduino.cc/en/Reference/Servo), and adds a few utility methods. Currently available extended functionality:

* properties `min` and `max` to change the pulse boundaries
* `void write(int angle, int delay)` : performs steps of 1 degree with a delay (ms) in between steps
* `int readMicroseconds()` : returns the current angle in microseconds

## More to come

I'll be adding more extended functionality over time:

* ServoGroup class: allows for controlling groups of servos, performing angle changes at the same time.
* Motion class: allows for defining motions (typically for ServoGroups) and run them as a combined action.
