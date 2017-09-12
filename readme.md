# NodeMCU ESP8266 Dallas Sensor encapsulation library
Simple encapsulation library for [DallasTemperature](https://github.com/milesburton/Arduino-Temperature-Control-Library) library, used for hiding OneWire and global variables.

# Usage

```C
#include <DallasSensor.h>

void setup()
{
    Serial.begin(9600);
    Dallas.begin(13); // 13 => data pin
    Dallas.printInfo();
}

void loop()
{
    Dallas.readTemperatures();
    Serial.println("Temperature: " + String(Dallas.getTemperature(0))); // 0 => index of the first sensor
    delay(60000);
}
```