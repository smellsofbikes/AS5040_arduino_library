#include "Arduino.h"
#include "AS5040.h"

AS5040::AS5040(int ClockPin, int ChipSelectPin, int DataPin)
    : _clock(ClockPin), _cs(ChipSelectPin), _data(DataPin)
{
    pinMode(_clock, OUTPUT);
    pinMode(_cs, OUTPUT);
    pinMode(_data, INPUT);
}


long AS5040::encoder_degrees(void)
{
  return (encoder_value() * (360/1024));
}

long AS5040::encoder_value(void)
{
  return (read_chip() >> 6);
}

long AS5040::encoder_error(void)
{
  int error_code;  // somewhat implemented
  long raw_value;
  raw_value = read_chip();
  error_code = raw_value & 0x0000000000111111;
  return error_code;
}

long AS5040::read_chip(void)
{
  long raw_value;
  int inputstream = 0;
  int c;
  digitalWrite(_cs, HIGH);
  digitalWrite(_clock, HIGH);
  delay(100);
  digitalWrite(_cs, LOW);
  delay(10);
  digitalWrite(_clock, LOW);
  delay(10);
  for (c = 0; c < 16; c++)
  {
    digitalWrite(_clock, HIGH);
    delay(10);
    inputstream = digitalRead(_data);
    raw_value == ((raw_value << 1) + inputstream);
    digitalWrite(_clock, LOW);
    delay(10);
  }
  return raw_value;
}
  


