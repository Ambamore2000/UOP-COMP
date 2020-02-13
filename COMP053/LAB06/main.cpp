#include <iostream>

#include "coastalcity.h"
#include "city.h"

unsigned int CoastalCity::coastalCityCount = 0;

int main() {

    CoastalCity ccity1("San Diego", 1500000, "Pacific Ocean", 5);

    cout << "The address of ccity1: " << &ccity1 << endl;
    // Stack

    CoastalCity *ccityPtr1 = nullptr;

    cout << "The value stored in ccityPtr1: " << ccityPtr1 << endl;

    ccityPtr1 = &ccity1;

    cout << "The address stored in ccityPtr1: " << ccityPtr1 << endl << endl;

    cout << "ccityPtr1 used to call printInfo()" << endl;
    cout << "Using -> syntax:" << endl;
    ccityPtr1->printInfo();
    cout << "Using * syntax:" << endl;
    (*ccityPtr1).printInfo();

    CoastalCity *ccityPtr2 = new CoastalCity;
    ccityPtr2->setName("Miami");
    ccityPtr2->setPopulation(500000);
    ccityPtr2->setWaterName("Atlantic Ocean");
    ccityPtr2->setBeachNum(8);

    cout << "The address stored in ccityPtr2: " << &ccityPtr2 << endl << endl;
    // Stack

    cout << "ccityPtr2 used to call printInfo()" << endl;
    cout << "Using -> syntax:" << endl;
    ccityPtr2->printInfo();
    cout << "Using * syntax:" << endl;
    (*ccityPtr2).printInfo();

    delete ccityPtr2;
    cout << "The address stored in ccityPtr2: " << &ccityPtr2 << endl;

    return 0;
}