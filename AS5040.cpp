#include "Arduino.h"
#include "AS5040.h"

AS5040::AS5040(int DataPin, int ClockPin, int ChipSelectPin)
           : _data(DataPin), _clock(ClockPin), _cs(ChipSelectPin)
{
    //Serial.println("Initializing");
    pinMode(_data, INPUT);
    pinMode(_clock, OUTPUT);
    pinMode(_cs, OUTPUT);
}


long AS5040::encoder_degrees(void)
{
  return ((encoder_value() * 360)/1024);
}

long AS5040::encoder_value(void)
{
  return (read_chip() >> 6);
}

long AS5040::encoder_error(void)
{
  int error_code;  // not yet implemented
  long raw_value;
  raw_value = read_chip();
  error_code = raw_value & 0x0000000000111111;
  return error_code;
}

long AS5040::read_chip(void)
{
  long raw_value = 0;
  int inputstream = 0;
  int c;
  //Serial.println("reading chip");
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
    //Serial.print("reading bit: ");
    //Serial.print(c);
    //Serial.print(" with value: ");
    //Serial.print(inputstream);
    raw_value = ((raw_value << 1) + inputstream);
    //Serial.print(" accumulated: ");
    //Serial.println(raw_value);
    digitalWrite(_clock, LOW);
    delay(10);
  }
  //Serial.print("exiting with value: ");
  //Serial.println(raw_value);
  return raw_value;
}
  








