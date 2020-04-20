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
void initSet(set<T> &inputSet, const T inputArray[], const int size) {
	for (int x = 0; x < size; x++) {
		inputSet.insert(inputArray[x]);
	}
}

template<typename T>
void printSet(const set<T> inputSet) {
	for (T element : inputSet) {
		cout << element << " ";
	}
	cout << endl << endl;
}

void printCitySet(const set<City> inputSet) {
	for (City c : inputSet) {
		c.printInfo();
	}
	cout << endl;
}

void cityNamesSet(const set<City> citySetInput, set<string> &nameSetInput) {
	for (City c : citySetInput) {
		nameSetInput.insert(c.getName());
	}
}

template<typename T>
void setIntersection(const set<T> inputSetOne, const set<T> inputSetTwo, set<T> &outputSet) {
	for (T element : inputSetOne) {
		if (inputSetTwo.count(element) == 1)
			outputSet.insert(element);
	}
}

template<typename T>
void setUnion(const set<T> inputSetOne, const set<T> inputSetTwo, set<T> &outputSet) {
	for (T element : inputSetOne) {
		outputSet.insert(element);
	}
	for (T element : inputSetTwo) {
		outputSet.insert(element);
	}
}

template<typename T>
bool isSubset(const set<T> inputSetOne, const set<T> inputSetTwo) {
	for (T element : inputSetOne) {
		if (inputSetTwo.count(element) == 0)
			return false;
	}
	return true;
}

void removeFromCitySet(set<City> &inputSet, const string name) {
	for (City c : inputSet) {
		if (c.getName() == name) {
			inputSet.erase(c);
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

	cout << "Union citySet1 and citySet2, and store the result in citySet3: " << endl;
	setUnion(citySet1, citySet2, citySet3);
	printCitySet(citySet3);

	cout << "citySet1 is a subset of citySet2? " << isSubset(citySet1, citySet2) << endl;
	cout << "citySet2 is a subset of citySet3? " << isSubset(citySet2, citySet3) << endl;
	cout << endl;

	cout << "Removing Sacramento from citySet1:" << endl;
	removeFromCitySet(citySet1, "Sacramento");
	printCitySet(citySet1);

	return 0;
}