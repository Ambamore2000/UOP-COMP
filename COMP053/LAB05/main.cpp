#include <iostream>
#include "coastalcity.h"
#include <vector>

unsigned int CoastalCity::coastalCityCount = 0;

int main() {

    CoastalCity sanDiego;
    sanDiego.setName("San Diego");
    sanDiego.setPopulation(1500000);
    sanDiego.setWaterName("Pacific Ocean");
    sanDiego.setBeachNum(5);

    sanDiego = sanDiego * 5;
    sanDiego.printInfo();

    CoastalCity miami;
    miami.setName("Miami");
    miami.setPopulation(500000);
    miami.setWaterName("Atlantic Ocean");
    miami.setBeachNum(8);

    CoastalCity thirdCoastalCity;
    thirdCoastalCity = sanDiego + miami;
    thirdCoastalCity.printInfo();

    cout << CoastalCity::getCoastalCityCount() << endl;

    return 0;
}