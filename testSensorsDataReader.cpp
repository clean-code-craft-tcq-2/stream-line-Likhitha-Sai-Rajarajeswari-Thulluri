#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "SensorsDataReader.h"

TEST_CASE("simulate and read data from sensors") {
  std::vector<SensorsData> sensorsDataHolder = readSensorsData("BMSData.txt");
  
  REQUIRE(sensorsDataHolder.size() == 50);
  
  struct SensorsData sensorsData;
  sensorsData.temperatureSensorData = 36.4;
  sensorsData.pressureSensorData = 27.3;
  
  REQUIRE(sensorsDataHolder[44] == sensorsData);
  
  sensorsData.temperatureSensorData = 38;
  sensorsData.pressureSensorData = 27;
  REQUIRE(sensorsDataHolder[21] == sensorsData);
  
  sensorsData.temperatureSensorData = 37.6;
  sensorsData.pressureSensorData = 28.9;
  REQUIRE(sensorsDataHolder[30] == sensorsData);
}

TEST_CASE("simulate and read data from wrong file") {
  std::vector<SensorsData> sensorsDataHolder = readSensorsData("BMSDtaa.txt");
  
  REQUIRE(sensorsDataHolder.size() == 0);
}
