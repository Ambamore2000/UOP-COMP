#include <iostream>
#include "coastalcity.h"
#include <vector>

int main() {

    City* cityOne = nullptr;
    City* cityTwo = nullptr;

    CoastalCity* coastalCityOne = nullptr;
    CoastalCity* coastalCityTwo = nullptr;

    vector<City*> cityVector;

    cityOne = new City();
    cityOne->setName("Denver");
    cityOne->setPopulation(750000);

    cityTwo = new City();
    cityTwo->setName("Reno");
    cityTwo->setPopulation(250000);

    coastalCityOne = new CoastalCity();
    coastalCityOne->setName("San Diego");
    coastalCityOne->setPopulation(250000);
    coastalCityOne->setWaterName("Pacific Ocean");
    coastalCityOne->setBeachNum(5);

    coastalCityTwo = new CoastalCity();
    coastalCityTwo->setName("Miami");
    coastalCityTwo->setPopulation(500000);
    coastalCityTwo->setWaterName("Atlantic Ocean");
    coastalCityTwo->setBeachNum(8);

    cityVector.push_back(cityOne);
    cityVector.push_back(cityTwo);
    cityVector.push_back(coastalCityOne);
    cityVector.push_back(coastalCityTwo);

    for (int x = 0; x < cityVector.size(); x++) {
        cityVector.at(x)->printInfo();
    }

    return 0;
}