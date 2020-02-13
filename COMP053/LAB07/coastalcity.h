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

    City* adjCity;
public:
    CoastalCity() {
        this->name = "N/A";
        this->population = 0;
        this->waterName = "N/A";
        this->beachNum = 0;
        adjCity = new City;
        adjCity->setName("N/A");
        adjCity->setPopulation(0);
        coastalCityCount++;
    }
    CoastalCity(string name, int population, string waterName, int beachNum, string adjCityName, int adjCityPopulation) {
        this->name = name;
        this->population = population;
        this->waterName = waterName;
        this->beachNum = beachNum;
        adjCity = new City;
        adjCity->setName(adjCityName);
        adjCity->setPopulation(adjCityPopulation);
    }

    string getWaterName() const { return waterName; }
    int getBeachNum() const { return beachNum; }

    void setWaterName(string waterName) { this->waterName = waterName; }
    void setBeachNum(int beachNum) { this->beachNum = beachNum; }

    void printInfo() const override {
        City::printInfo();
        cout <<"Water: " << getWaterName() << endl;
        cout <<"No. of Beaches: " <<getBeachNum() << endl;

        cout << "Adjacent City:" << endl;
        adjCity->printInfo();
    }

    CoastalCity operator*(int rhs) {
        CoastalCity newCity;

        newCity.setName(getName());
        newCity.setPopulation(getPopulation());
        newCity.setWaterName(getWaterName());

        newCity.setBeachNum(getBeachNum() * rhs);

        return newCity;
    };

    CoastalCity operator+(CoastalCity rhs) {
        CoastalCity newCity;

        newCity.setName(getName().append(rhs.getName()));
        newCity.setPopulation(getPopulation() + rhs.getPopulation());
        newCity.setWaterName(getWaterName().append(rhs.getWaterName()));
        newCity.setBeachNum(getBeachNum() + rhs.getBeachNum());

        return newCity;
    };

    unsigned static int getCoastalCityCount() {
        return coastalCityCount;
    };

    City* getAdjCity() {
        return adjCity;
    }


    ~CoastalCity() {
        delete adjCity;
    }

};

#endif //LAB03_COASTALCITY_H
