#include<vector>

struct SensorsData{
  int temperatureSensorData;
  int pressureSensorData;
  
  bool operator==(const SensorsData &other) const {
     if((temperatureSensorData==other.temperatureSensorData) && (pressureSensorData==other.pressureSensorData))
        return true;
     return false;
    }
};
  
std::vector<SensorsData> readSensorsData();
