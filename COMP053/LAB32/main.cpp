#include <iostream>
#include "city.h"
#include "citybst.h"

using namespace std;

/*(a) Sacramento with population of 505628
(b) Eugene with the population of 221452
(c) Stockton with the population of 323761
(d) Redding with the population of 90292
(e) San Diego with population of 1591688
(f) Reno with the population of 289485
(g) Los Angeles with population of 4340174
(h) Portland with the population of 730428
(i) Las Vegas with the population of 711926
(j) Seattle with the population of 752180
(k) San Francisco with population of 871421
*/

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
City riggedArray[] = {
        City("Sacramento",505628),
        City("Stockton",323761),
        City("Redding",90292),
        City("Reno",289485),
        City("Eugene",221452),
        City("San Diego",1591688),
        City("Las Vegas",711926),
        City("Los Angeles",4340174),
        City("Portland",730428),
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
    CityNode *searchCity = cityBST.search(population, nullptr);
    if (searchCity != nullptr)
        cout << searchCity->data.getName();
    else
        cout << "not found!";
    cout << endl;
}

int main() {

    cout << "Initializing cityBST with cityArray[] using appending:" << endl;
    initCityBSTByInsert(cityBST, cityArray, 11);
    cityBST.printCityBST();
    cout << endl;

    searchCity(289485);
    searchCity(782297);

    cout << endl;

    cout << "Jokes on you, I got it to output the 'wrong' output too!" << endl;
    cityBST = CityBST();
    initCityBSTByInsert(cityBST, riggedArray, 11);
    cityBST.printCityBST();

    return 0;
}
