#include <iostream>
#include <set>
#include <utility>
#include "city.h"

int a[] = {2,8,1,7,3};
City cityArray1[] = {
	City("Los Angeles", 4000000),
	City("San Diego", 1500000),
	City("San Francisco", 900000),
	City("Sacramento", 500000),
	City("Stockton", 300000)
};
City cityArray2[] = {
	City("Redding", 90000),
	City("Stockton", 300000),
	City("Las Vegas", 700000),
	City("Reno", 300000),
	City("Portland", 700000),
	City("Sacramento", 500000),
	City("Eugene", 200000)
};

set<int> intSet;
set<City> citySet1, citySet2, citySet3;
set<string> cityNames;

template<typename T>
void initSet(set<T> &elementSet, T elementArray[], int size) {
	// Is elementSet empty?
	for (int i = 0; i < size; ++i) {
		elementSet.insert(elementArray[i]);
	}
}

template<typename T>
void printSet(const set<T> elementSet) {
	for (T elements : elementSet) {
		cout << elements << " ";
	}
	cout << endl << endl;
}

void printCitySet(const set<City> setToPrint) {
	for (City cities : setToPrint) {
		cities.printInfo();
	}
	cout << endl;
}

void cityNamesSet(const set<City> cityNamesSet, set<string> &stringNamesSet) {
	for (City cities : cityNamesSet) {
		stringNamesSet.insert(cities.getName());
	}
}

template<typename T>
void setIntersection(const set<T> setFirstInt, const set<T> setSecondInt, set<T> &setToOutput) {
	typename set<T>::iterator firstIt;
	typename set<T>::iterator secondIt;

	for (T firstSetElements : setFirstInt) {
		for (T secondSetElements : setSecondInt) {
			if (*&firstSetElements < *&secondSetElements)
				return;
		}
	}
}

template<typename T>
void setUnion(const set<T> setFirstUni, const set<T> setSecondUni, set<T> &setToOutput) {
	for (T firstSetElements : setFirstUni) {
		setToOutput.insert(firstSetElements);
	}
	for (T secondSetElements : setSecondUni) {
		setToOutput.insert(secondSetElements);
	}
	//TODO Ask "Are sets in C++ the same idea of "Sets" in Discrete Math? I noticed that two of the same elements in a set only prints once."
}

template<typename T>
bool isSubset(const set<T> firstSetComp, const set<T> secondSetComp) {
	for (T secondSetElements : secondSetComp) {
		bool bothContainElement = false;
		for (T firstSetElements : firstSetComp) {
			if (&firstSetElements == &secondSetElements) {
				bothContainElement = true;
				break; //TODO get rid of this break?
			}
		}
		if (!bothContainElement)
			return false;
	}
	return true;
}

void removeFromCitySet(set<City> &citySetToRemove, const string name) {
	for (City cities : citySetToRemove) {
		if (cities.getName().compare(name) == 0) {
			citySetToRemove.erase(cities);
			break;
		}
	}
}

int main() {

	cout << "Initializing intSet with a[]:" << endl;
	initSet(intSet, a, 5);
	printSet(intSet);

	cout << "Initializing citySet1 with cityArray1[]:" << endl;
	initSet(citySet1, cityArray1, 5);
	printCitySet(citySet1);

	cout << "Initializing citySet2 with cityArray2[]:" << endl;
	initSet(citySet2, cityArray2, 7);
	printCitySet(citySet2);

	cout << "Populate cityNames according to the cities in citySet1:" << endl;
	cityNamesSet(citySet1, cityNames);
	printSet(cityNames);

	cout << "Intersect citySet1 and citySet2, and store the result in citySet3:" << endl;
	setIntersection(citySet1, citySet2, citySet3);
	printCitySet(citySet3);

	cout << "Union citySet1 and citySet2, and store the result in citySet3:" << endl;
	setUnion(citySet1, citySet2, citySet3);
	printCitySet(citySet3);

	cout << "citySet1 is a subset of citySet2? " << isSubset(citySet1, citySet2) << endl;
	cout << "citySet2 is a subset of citySet3? " << isSubset(citySet2, citySet3) << endl << endl;

	cout << "Removing Sacramento from citySet1:" << endl;
	removeFromCitySet(citySet1, "Sacramento");
	printCitySet(citySet1);
	return 0;
}