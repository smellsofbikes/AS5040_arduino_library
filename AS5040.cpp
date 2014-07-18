#include "Arduino.h"
#include "AS5040.h"

AS5040::AS5040(int ClockPin, int ChipSelectPin, int DataPin)
{
  init(ClockPin, ChipSelectPin, DataPin);
}

void AS5040::init(int ClockPin, int ChipSelectPin, int DataPin)
{
  _clock = ClockPin;
  _cs = ChipSelectPin;
  _data = DataPin;
  pinMode(ClockPin, OUTPUT);
  pinMode(ChipSelectPin, OUTPUT);
  pinMode(DataPin, INPUT);
}

long AS5040::measured_degrees(void)
{
  long measured_degrees;
  long raw_value;
  long anglemask = 262080; // 0x111111111111000000: mask to obtain first 12
                           //  digits with position info

  raw_value = read_chip();
  raw_value = raw_value & anglemask; // mask out error
  raw_value = (raw_value >> 6);      // shift over
  measured_degrees = raw_value * 0.352; // angle * (360/1024)
  return measured_degrees;
}

long AS5040::measured_value(void)
{
  long raw_value;
  long anglemask = 262080; // 0x111111111111000000: mask to obtain first 12
                           //  digits with position info
  raw_value = read_chip();
  raw_value = raw_value & anglemask; // mask out error
  raw_value = (raw_value >> 6);      // shift over

  return raw_value;
}

int AS5040::error(void)
{
  int error_code = 0;  // not yet implemented
  return error_code;
}

int AS5040:read_chip(void)
{
  long raw_value;
  return raw_value;
}
  






