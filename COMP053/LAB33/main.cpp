#include <iostream>
#include "city.h"
#include "citybst.h"

City cityArray[] = {
        City("Sacramento",505628),
        City("Eugene",221452),
        City("Stockton",323761),
        City("Redding",90292),
        City("San Diego",1591688),
        City("Reno",289485),
        City("Los Angeles",4340174),
        City("Portland",730428),
        City("Las Vegas",711926),
        City("Seattle",752180),
        City("San Francisco",871421)
};

CityBST cityBST;

void initCityBSTByInsert(CityBST &inputCityBST, City inputCityArray[], int size) {
    for (int x = 0; x < size; x++) {
        inputCityBST.insert(new CityNode(inputCityArray[x]));
    }
}

void searchCity(int population) {
    cout << "Searching in cityBST for the city with population " << population << ": ";
    CityNode *searchCity = cityBST.search(population);
    if (searchCity != nullptr)
        cout << searchCity->data.getName();
    else
        cout << "not found!";
    cout << endl;
}

void removeCity(string cityName, int population) {
    cout << "Removing city with population " << population << " (" << cityName << "):" << endl;
    cityBST.remove(population);
    cityBST.printCityBST();
    cout << endl;
}

void getHeight() {
    cout << "Height of cityBST: " << cityBST.getHeight() << endl << endl;
}

int main() {
    cout << "Initializing cityBST with cityArray[] using appending:" << endl;

    initCityBSTByInsert(cityBST, cityArray, 11);
    cityBST.printCityBST();
    cout << endl;

    getHeight();

    searchCity(289485);
    searchCity(782297);
    cout << endl;

    removeCity("San Francisco", 871421);
    removeCity("Stockton", 323761);
    removeCity("Sacramento", 505628);

    getHeight();

    cout << "cityBST inorder traversal and printing:" << endl;
    cityBST.printCityBST_InOrder();

    return 0;
}
