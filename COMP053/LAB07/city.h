//
// Created by Andki on 1/19/2020.
//

#ifndef LAB03_CITY_H
#define LAB03_CITY_H

#include <string>
#include <iostream>
using namespace std;
class City {
public:
    void setName(string name) { this->name = name; }
    void setPopulation(unsigned int population) { this->population = population; }
    string getName() const { return this->name; }
    unsigned int getPopulation() const { return this->population; }

    virtual void printInfo() const {
        cout <<"Name: " << getName() << endl;
        cout <<"Population: " <<getPopulation() << endl;
    }

    City();
    City(string name, int population);
protected:
    string name;
    unsigned int population;
};

City::City() {
    name = "N/A";
    population = 0;
}

City::City(string name, int population) {
    this->name = name;
    this->population = population;
}

#endif //LAB03_CITY_H
