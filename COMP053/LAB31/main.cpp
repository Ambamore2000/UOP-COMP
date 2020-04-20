#include <iostream>
#include<string>
#include "city.h"
#include "citylist.h"
#include "cityqueue.h"
#include "citydeque.h"

using namespace std;

City cityArray[] = {
		City("Los Angeles",4340174),
		City("San Diego",1591688),
		City("San Francisco",871421),
		City("Sacramento",505628),
		City("Stockton",323761),
		City("Redding",90292),
		City("Las Vegas",711926),
		City("Reno",289485),
		City("Portland",730428),
		City("Seattle",752180),
		City("Eugene",221452)
};

CityList cityList;

void initCityListByAppend(CityList &inputCityList, City inputCityArray[], int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		inputCityList.append(new CityNode(inputCityArray[i]));
	}
}

int main() {

	cout << "Initializing cityList1 with cityArray[] using appending:" << endl;
	initCityListByAppend(cityList, cityArray, 11);
	cityList.printCityList();
	cout << endl;

    CityQueue *cityQueue = new CityQueue(cityList);
    CityDeque *cityDeque = new CityDeque(cityList);

    if (cityQueue->peekCityNode() != nullptr) {
        cout << "Reading the front of cityQueue:" << endl;
        cityQueue->peekCityNode()->data.printInfo();
    }

    cout << "Phoenix pushed to cityQueue." << endl;
    cityQueue->pushCityNode(new CityNode(City("Phoenix", 1660472)));
    cout << "Santa Fe pushed to cityQueue." << endl;
    cityQueue->pushCityNode(new CityNode(City("Santa Fe", 84263)));
    cout << "Front of cityQueue is popped." << endl;
    cityQueue->popCityNode();

    cout << "Reading the front of cityQueue:" << endl;
    if (cityQueue->peekCityNode() != nullptr)
        cityQueue->peekCityNode()->data.printInfo();

    cout << "Check if cityQueue is empty: " << cityQueue->isEmpty() << endl << endl;

    cout << "Reading the front of cityDeque:" << endl;
    if (cityDeque->peekFrontCityNode() != nullptr)
        cityDeque->peekFrontCityNode()->data.printInfo();
    cout << "Reading the back of cityDeque:" << endl;
    if (cityDeque->peekBackCityNode() != nullptr)
        cityDeque->peekBackCityNode()->data.printInfo();

    cout << "Phoenix pushed to the front of cityDeque." << endl;
    cityDeque->pushFrontCityNode(new CityNode(City("Phoenix", 1660472)));
    cout << "Santa Fe pushed to the back of cityDeque." << endl;
    cityDeque->pushBackCityNode(new CityNode(City("Santa Fe", 84263)));

    cout << "Popping the front of cityDeque and printing it:" << endl;
    if (cityDeque->peekFrontCityNode() != nullptr)
        cityDeque->popFrontCityNode()->data.printInfo();
    cout << "Popping the back of cityDeque and printing it:" << endl;
    if (cityDeque->peekBackCityNode() != nullptr)
        cityDeque->peekBackCityNode()->data.printInfo();

	return 0;
}