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
  something();
  return measured_degrees;
}

long AS5040::measured_value(void)
{
  something();
  return measured_value;
}

int AS5040::error(void)
{
  something();
  return error_code;
}


