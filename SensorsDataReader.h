#include<vector>

struct SensorsData{
  float temperatureSensorData;
  float pressureSensorData;
  
  bool operator==(const SensorsData &other) const {
     if((temperatureSensorData==other.temperatureSensorData) && (pressureSensorData==other.pressureSensorData))
        return true;
     return false;
    }
};
  
std::vector<SensorsData> readSensorsData();

void printOnConsole(SensorsData sensorsData);

void inferSensorData();
