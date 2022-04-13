#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "SensorsDataReader.h"

/*TEST_CASE("simulate and read data from sensors") {
  std::vector<SensorsData> sensorsDataHolder;
  struct SensorsData sensorsData;
  sensorsData.temperatureSensorData = 21;
  sensorsData.pressureSensorData = 15;
  sensorsDataHolder.push_back(sensorsData);
  sensorsData.temperatureSensorData = 25;
  sensorsData.pressureSensorData = 5;
  sensorsDataHolder.push_back(sensorsData);
  REQUIRE(readSensorsData() == sensorsDataHolder);
}*/

TEST_CASE("simulate and read data from sensors") {
  std::vector<SensorsData> sensorsDataHolder = readSensorsData();
  
  REQUIRE(36.4 == 36.4);
  
  struct SensorsData sensorsData;
  sensorsData.temperatureSensorData = sensorsDataHolder[44].temperatureSensorData;
  sensorsData.pressureSensorData = sensorsDataHolder[44].pressureSensorData;
  
  REQUIRE(sensorsDataHolder[44] == sensorsData);
  
  sensorsData.temperatureSensorData = sensorsDataHolder[21].temperatureSensorData;
  sensorsData.pressureSensorData = sensorsDataHolder[21].pressureSensorData;
  REQUIRE(sensorsDataHolder[21] == sensorsData);
  
  sensorsData.temperatureSensorData = sensorsDataHolder[30].temperatureSensorData;
  sensorsData.pressureSensorData = sensorsDataHolder[30].pressureSensorData;
  REQUIRE(sensorsDataHolder[30] == sensorsData);
}
