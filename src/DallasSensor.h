#ifndef _dallas_sensor_h
#define _dallas_sensor_h

#include <DallasTemperature.h>

class DallasSensor
{
  public:
    void begin(byte dataPin);
    void printInfo();
    float getTemperature(byte index);
};

extern DallasSensor Dallas;

#endif // _dallas_sensor_h