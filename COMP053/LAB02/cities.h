#ifndef LAB02_CITIES_H
#define LAB02_CITIES_H

#include <vector>
#include "city.h"

class Cities {
private:
    vector<City> cityList;
public:
    void readCities();
    void printCityList();
};


#endif //LAB02_CITIES_H
