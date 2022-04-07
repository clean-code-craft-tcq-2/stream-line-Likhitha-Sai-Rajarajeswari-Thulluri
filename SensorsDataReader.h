#include<vector>

struct SensorsData{
  int temperatureSensorData;
  int pressureSensorData;
};
  
std::vector<SensorsData> readSensorsData();
