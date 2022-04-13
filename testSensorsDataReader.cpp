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
  
  REQUIRE(sensorsDataHolder[44].temperatureSensorData == 36.4f);
  REQUIRE(sensorsDataHolder[44].pressureSensorData == 27.3f);
     
  REQUIRE(sensorsDataHolder[21].temperatureSensorData == 38f);
  REQUIRE(sensorsDataHolder[21].pressureSensorData == 27f);
  
  REQUIRE(sensorsDataHolder[30].temperatureSensorData == 37.6f);
  REQUIRE(sensorsDataHolder[30].pressureSensorData == 28.9f);
}
