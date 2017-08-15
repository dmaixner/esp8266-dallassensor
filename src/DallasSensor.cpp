#include "DallasSensor.h"
#include <OneWire.h>

DallasTemperature *sensors = NULL;

void DallasSensor::begin(byte dataPin)
{
    OneWire *oneWire = NULL;
    oneWire = new OneWire(dataPin);
    sensors = new DallasTemperature(oneWire);
    sensors->begin();
    // sensors->setResolution(12);
    // sensors.setWaitForConversion(true);
}

void DallasSensor::printInfo()
{
    Serial.println("Dallas");
    Serial.println(" - sensors count: " + String(sensors->getDeviceCount()));
    Serial.println(" - resolutin: " + String(sensors->getResolution()));
    Serial.println(" - wait for conversion: " + String(sensors->getWaitForConversion() ? "true" : "false"));
    Serial.println(" - check for conversion: " + String(sensors->getCheckForConversion() ? "true" : "false"));
    Serial.println(" - parasite power mode: " + String(sensors->isParasitePowerMode() ? "true" : "false"));
    Serial.println("----------------------");
}

float DallasSensor::getTemperature(byte index)
{
    sensors->requestTemperatures();
    return sensors->getTempCByIndex(index);
}

DallasSensor Dallas;
