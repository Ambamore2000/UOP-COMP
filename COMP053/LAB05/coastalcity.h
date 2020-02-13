//
// Created by Andki on 1/19/2020.
//

#ifndef LAB03_COASTALCITY_H
#define LAB03_COASTALCITY_H

#include "city.h"

class CoastalCity : public City {
private:
    string waterName; //a string that stores the body of the water adjacent to the coastal city
    int beachNum; //an integer that stores the number of beaches that the coastal city has.

    unsigned static int coastalCityCount;
public:
    CoastalCity() {
        this->name = "N/A";
        this->population = 0;
        this->waterName = "N/A";
        this->beachNum = 0;
        coastalCityCount++;
    }

    string getWaterName() const { return waterName; }
    int getBeachNum() const { return beachNum; }

    void setWaterName(string waterName) { this->waterName = waterName; }
    void setBeachNum(int beachNum) { this->beachNum = beachNum; }

    void printInfo() const override {
        City::printInfo();

        cout <<"Water: " << getWaterName() << endl;
        cout <<"No. of Beaches: " <<getBeachNum() << endl << endl;
    }
    CoastalCity operator*(int rhs);
    CoastalCity operator+(CoastalCity rhs);

    static int getCoastalCityCount();
};

CoastalCity CoastalCity::operator*(int rhs) {
    CoastalCity newCity;

    newCity.setName(getName());
    newCity.setPopulation(getPopulation());
    newCity.setWaterName(getWaterName());

    newCity.setBeachNum(getBeachNum() * rhs);

    return newCity;
}

CoastalCity CoastalCity::operator+(CoastalCity rhs) {
    CoastalCity newCity;

    newCity.setName(getName().append(rhs.getName()));
    newCity.setPopulation(getPopulation() + rhs.getPopulation());
    newCity.setWaterName(getWaterName().append(rhs.getWaterName()));
    newCity.setBeachNum(getBeachNum() + rhs.getBeachNum());

    return newCity;
}

int CoastalCity::getCoastalCityCount() {
    return coastalCityCount;
}

#endif //LAB03_COASTALCITY_H
