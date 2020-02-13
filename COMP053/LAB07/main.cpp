#include <iostream>

#include "coastalcity.h"
#include "city.h"

unsigned int CoastalCity::coastalCityCount = 0;

int main() {

    CoastalCity* ccityPtr = new CoastalCity("Miami",
                                            500000,
                                            "Atlantic ocean",
                                            8,
                                            "Coral Gables",
                                            50000);

    City* adjCity = ccityPtr->getAdjCity();

    cout << "address of coastal city: " << &ccityPtr << endl;
    cout << "address of adjacted city: " << &adjCity << endl;

    ccityPtr->printInfo();

    delete ccityPtr;

    return 0;
}