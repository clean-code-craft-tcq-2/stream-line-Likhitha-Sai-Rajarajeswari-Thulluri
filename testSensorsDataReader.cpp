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
  REQUIRE(sensorsDataHolder[45].temperatureSensorData == 36.4);
  REQUIRE(sensorsDataHolder[45].pressureSensorData == 27.3);
     
  REQUIRE(sensorsDataHolder[22].temperatureSensorData == 38);
  REQUIRE(sensorsDataHolder[22].pressureSensorData == 27);
  
  REQUIRE(sensorsDataHolder[31].temperatureSensorData == 37.6);
  REQUIRE(sensorsDataHolder[31].pressureSensorData == 28.9);
}
