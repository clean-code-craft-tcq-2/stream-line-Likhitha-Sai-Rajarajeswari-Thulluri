#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "SensorsDataReader.h"

std::vector<SensorsData> readSensorsData() {
  std::vector<SensorsData> sensorsDataHolder;
  std::ifstream File;
  File.open("BMSData.txt", std::ios_base::out);
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
