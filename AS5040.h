#ifndef AS5040_h
#define AS5040_h

#include "Arduino.h"

class AS5040
{
  public:
    AS5040(int DataPin, int ClockPin, int ChipSelectPin);
    long encoder_degrees(void);
    long encoder_value(void);
    long encoder_error(void);
  private:
    long read_chip(void);
    const int _clock;        // clock pin: output from arduino to as5040
    const int _cs;           // chip select: output
    const int _data;         // data pin: input
    
};

#endif
