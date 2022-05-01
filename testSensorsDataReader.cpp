#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "SensorsDataReader.h"

TEST_CASE("simulate and read data from sensors") {
  std::vector<SensorsData> sensorsDataHolder = readSensorsData("BMSData.txt");
  
  REQUIRE(sensorsDataHolder.size() == 50);
  
  struct SensorsData sensorsData;
  sensorsData.temperatureSensorData = 36.4;
  sensorsData.pressureSensorData = sensorsDataHolder[44].pressureSensorData;
  
  REQUIRE(sensorsDataHolder[44] == sensorsData);
  
  sensorsData.temperatureSensorData = sensorsDataHolder[21].temperatureSensorData;
  sensorsData.pressureSensorData = sensorsDataHolder[21].pressureSensorData;
  REQUIRE(sensorsDataHolder[21] == sensorsData);
  
  sensorsData.temperatureSensorData = sensorsDataHolder[30].temperatureSensorData;
  sensorsData.pressureSensorData = sensorsDataHolder[30].pressureSensorData;
  REQUIRE(sensorsDataHolder[30] == sensorsData);
}

TEST_CASE("simulate and read data from wrong file") {
  std::vector<SensorsData> sensorsDataHolder = readSensorsData("BMSDtaa.txt");
  
  REQUIRE(sensorsDataHolder.size() == 0);
}
