#ifndef AS5040_h
#define AS5040_h

#include "Arduino.h"

class AS5040
{
  public:
    AS5040(int ClockPin, int ChipSelectPin, int DataPin);
    void init(int ClockPin, int ChipSelectPin, int DataPin);
    long measured_degrees(void);
    long measured_value(void);
    int error(void);
  private:
    long read_chip(void)
    int _clock;
    int _cs;
    int _data;
};

#endif
