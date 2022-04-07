#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "SensorsDataReader.h"

TEST_CASE("simulate and read data from sensors") {
  std::vector<SensorsData> sensorsDataHolder;
  Struct SensorsData sensorsData;
  sensorsData.temperatureSensor = 21;
  sensorsData.pressureSensor = 15;
  sensorsDataHolder.push_back(sensorsData);
  sensorsData.temperatureSensor = 25;
  sensorsData.pressureSensor = 5;
  sensorsDataHolder.push_back(sensorsData);
  REQUIRE(readSensorsData() == sensorsDataHolder);
}
