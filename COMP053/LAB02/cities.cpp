#include <iostream>
#include "cities.h"

void Cities::readCities() {
    string cityName;
    int populationSize;

    cout << "City:";

    while (cityName != "X") {
        cin >> cityName;
        if (cityName == "X")
            break;
        cout << "Population:";
        cin >> populationSize;

        City newCity(cityName, populationSize);
        cityList.push_back(newCity);
        cout << "City:";
    }
}

void Cities::printCityList() {
    for (int x = 0; x < cityList.size(); x++) {
        City city = cityList.at(x);
        cout << city.getName() << ": " << city.getPopulation() << endl;
    }
}
