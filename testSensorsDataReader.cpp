#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "SensorsDataReader.h"

TEST_CASE("simulate and read data from sensors") {
  std::vector<SensorsData> sensorsDataHolder;
  struct SensorsData sensorsData;
  sensorsData.temperatureSensorData = 21;
  sensorsData.pressureSensorData = 15;
  sensorsDataHolder.push_back(sensorsData);
  sensorsData.temperatureSensorData = 25;
  sensorsData.pressureSensorData = 5;
  sensorsDataHolder.push_back(sensorsData);
  REQUIRE(readSensorsData() == sensorsDataHolder);
}
