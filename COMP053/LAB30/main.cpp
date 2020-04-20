#include <iostream>
#include<string>
#include "city.h"
#include "citylist.h"
#include "citystack.h"

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

	cout << "Searching for Stockton in cityList, if found print its population:" << endl;
	CityNode *foundCity = cityList.search("Stockton");
	if (foundCity != nullptr)
	    cout << foundCity->data.getPopulation() << endl;
    cout << endl;

    CityStack *cityStack = new CityStack(cityList);

	cout << "Reading the top of cityStack:" << endl;
    if (!cityStack->isEmpty()) cityStack->peekCityNode()->data.printInfo();

	cout << "Phoenix pushed." << endl;
	cityStack->pushCityNode(new CityNode(City("Phoenix", 1660472)));
    cout << "Santa Fe pushed." << endl;
	cityStack->pushCityNode(new CityNode(City("Santa Fe", 84263)));

	cout << "Top of stack is popped." << endl;
	cityStack->popCityNode();

	cout << "Reading the top of cityStack:" << endl;
	if (!cityStack->isEmpty()) cityStack->peekCityNode()->data.printInfo();

	return 0;
}