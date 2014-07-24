#include "Arduino.h"
#include "AS5040.h"

AS5040::AS5040(uint16_t DataPin, uint16_t ClockPin, uint16_t ChipSelectPin)
           : _data(DataPin), _clock(ClockPin), _cs(ChipSelectPin)
{
    //Serial.println("Initializing");
    pinMode(_data, INPUT);
    pinMode(_clock, OUTPUT);
    pinMode(_cs, OUTPUT);
}


uint32_t AS5040::encoder_degrees(void)
{
  return ((encoder_value() * 360)/1024);
}

uint32_t AS5040::encoder_value(void)
{
  return (read_chip() >> 6);
}

uint32_t AS5040::encoder_error(void)
{
  uint16_t error_code;  // not yet implemented
  uint32_t raw_value;
  raw_value = read_chip();
  Serial.print("raw code: ");
  Serial.print(raw_value);
  error_code = raw_value & 0b0000000000111111;
  Serial.print("clipped: ");
  Serial.println(error_code);
  return error_code;
}

uint32_t AS5040::read_chip(void)
{
  uint32_t raw_value = 0;
  uint16_t inputstream = 0;
  uint16_t c;
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
  











