#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "SensorsDataReader.h"

std::vector<SensorsData> readSensorsData(const char* fileName) {
  std::vector<SensorsData> sensorsDataHolder;
  std::ifstream File;
  File.open(fileName, std::ios_base::out);
  if (File.is_open())
  {
    struct SensorsData sensorsData;
    while (File >> sensorsData.temperatureSensorData) {
      File >>  sensorsData.pressureSensorData;
      sensorsDataHolder.push_back(sensorsData);
    }
  }
  return sensorsDataHolder;
}

void printOnConsole(SensorsData sensorsData)
{
  std::cout<<sensorsData.temperatureSensorData<<", "<<sensorsData.pressureSensorData<<std::endl;
}

void inferSensorData(const char* fileName)
{
  std::vector<SensorsData> sensorsDataHolder = readSensorsData(fileName);
  for(SensorsData sensorsData: sensorsDataHolder) 
  {
    printOnConsole(sensorsData);
  }    
}
