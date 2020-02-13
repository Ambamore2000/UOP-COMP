#include <iostream>
#include "coastalcity.h"

int main() {

    CoastalCity sanFransisco;

    sanFransisco.printInfo();

    sanFransisco.setName("San Fransisco");
    sanFransisco.setPopulation(900000);
    sanFransisco.setWaterName("SF Bay");
    sanFransisco.setBeachNum(10);

    sanFransisco.printInfo();

    return 0;
}