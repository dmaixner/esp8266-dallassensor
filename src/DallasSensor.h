#ifndef _dallas_sensor_h
#define _dallas_sensor_h

class DallasSensor
{
  public:
    void begin(const byte dataPin);
    void printInfo();
    void readTemperatures();
    float getTemperature(const byte index);
    byte getDeviceCount();
};

extern DallasSensor Dallas;

#endif // _dallas_sensor_h