#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <iostream>
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
  std::cout<<sensorsDataHolder[46].temperatureSensorData<<std::endl;
  std::cout<<sensorsDataHolder[46].pressureSensorData<<std::endl;;
  
  REQUIRE(sensorsDataHolder[46].temperatureSensorData == 36.4);
  REQUIRE(sensorsDataHolder[46].pressureSensorData == 27.3);
     
  REQUIRE(sensorsDataHolder[23].temperatureSensorData == 38);
  REQUIRE(sensorsDataHolder[23].pressureSensorData == 27);
  
  REQUIRE(sensorsDataHolder[32].temperatureSensorData == 37.6);
  REQUIRE(sensorsDataHolder[32].pressureSensorData == 28.9);
}
