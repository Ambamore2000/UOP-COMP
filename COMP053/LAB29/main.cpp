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

CityList cityList1, cityList2;

void initCityListByAppend(CityList &inputCityList, City inputCityArray[], int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		inputCityList.append(new CityNode(inputCityArray[i]));
	}
}
void initCityListByPrepend(CityList &inputCityList, City inputCityArray[], int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		inputCityList.prepend(new CityNode(inputCityArray[i]));
	}
}

int main() {

	cout << "Initializing cityList1 with cityArray[] using appending:" << endl;
	initCityListByAppend(cityList1, cityArray, 11);
	cityList1.printCityList();

	cout << "Initializing cityList2 with cityArray[] using prepending:" << endl;
	initCityListByPrepend(cityList2, cityArray, 11);
	cityList2.printCityList();

	cout << "Searching for Stockton in cityList, and inserting Phoenix after it:" << endl;
	CityNode *phoenix = new CityNode(City("Phoenix",1660472));
	cityList1.insert(cityList1.search("Stockton"), phoenix);
	cityList1.printCityList();

	cout << "Searching for Reno in cityList, and removing that node:" << endl;
	cityList2.remove(cityList2.search("Reno"));
	cityList2.printCityList();

	return 0;
}