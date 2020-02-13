#ifndef LAB02_CITY_H
#define LAB02_CITY_H

#include <string>
using namespace std;

class City {
public:
    void setName(string name) {
        this->name = name;
    }
    void setPopulation(unsigned int population) {
        this->population = population;
    }

    string getName() {
        return name;
    }
    int getPopulation () {
        return population;
    }

    City() {
        name = "N/A";
        population = 0;
    }
    City(string name, int population) {
        this->name = name;
        this->population = population;
    }

private:
    string name;
    int population;
};


#endif //LAB02_CITY_H
