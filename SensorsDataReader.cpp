#include"SensorsDataReader.h"

std::vector<SensorsData> readSensorsData() {
  std::vector<SensorsData> sensorsDataHolder;
  struct SensorsData sensorsData;
  sensorsData.temperatureSensorData = 21;
  sensorsData.pressureSensorData = 15;
  sensorsDataHolder.push_back(sensorsData);
  sensorsData.temperatureSensorData = 25;
  sensorsData.pressureSensorData = 5;
  sensorsDataHolder.push_back(sensorsData);
  return sensorsDataHolder;
}
