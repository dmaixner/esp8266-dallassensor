#include <OneWire.h>
#include <DallasTemperature.h>
#include "DallasSensor.h"

DallasTemperature *sensors = NULL;

void DallasSensor::begin(const byte dataPin)
{
    OneWire *oneWire = NULL;
    oneWire = new OneWire(dataPin);
    sensors = new DallasTemperature(oneWire);
    sensors->begin();
    // sensors->setResolution(12);
    // sensors->setWaitForConversion(true);
    // sensors->seCheckForConversion(true);
}

void DallasSensor::printInfo()
{
    Serial.println("Dallas");
    Serial.println(" - sensors count: " + String(sensors->getDeviceCount()));
    Serial.println(" - resolution: " + String(sensors->getResolution()));
    Serial.println(" - wait for conversion: " + String(sensors->getWaitForConversion() ? "true" : "false"));
    Serial.println(" - check for conversion: " + String(sensors->getCheckForConversion() ? "true" : "false"));
    Serial.println(" - parasite power mode: " + String(sensors->isParasitePowerMode() ? "true" : "false"));
    Serial.println("----------------------");
}

float DallasSensor::getTemperature(const byte index)
{
    sensors->requestTemperatures();
    return sensors->getTempCByIndex(index);
}

DallasSensor Dallas;
