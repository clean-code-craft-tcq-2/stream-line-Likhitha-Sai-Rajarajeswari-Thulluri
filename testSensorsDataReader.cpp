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
  
  REQUIRE(sensorsDataHolder[44].temperatureSensorData == 36.4);
  REQUIRE(sensorsDataHolder[44].pressureSensorData == 27.3);
     
  REQUIRE(sensorsDataHolder[21].temperatureSensorData == 38);
  REQUIRE(sensorsDataHolder[21].pressureSensorData == 27);
  
  REQUIRE(sensorsDataHolder[30].temperatureSensorData == 37.6);
  REQUIRE(sensorsDataHolder[30].pressureSensorData == 28.9);
}
