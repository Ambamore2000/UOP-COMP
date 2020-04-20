#include <iostream>
#include<string>
#include "city.h"
#include "citylist.h"

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

	cout << "Initializing cityList with cityArray[] using appending:" << endl;
	initCityListByAppend(cityList, cityArray, 11);
	cityList.printCityList();

	cout << "Searching for Stockton in cityList, and inserting Phoenix after it:" << endl;
	CityNode *phoenix = new CityNode(City("Phoenix",1660472));
	cityList.insert(cityList.search("Stockton"), phoenix);
	cityList.printCityList();

	cout << "Searching for Reno in cityList, and removing the node after it:" << endl;
	cityList.remove(cityList.search("Reno"));
	cityList.printCityList();

	return 0;
}