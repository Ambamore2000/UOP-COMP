#include <iostream>

#include <list>
#include "city.h"

int a[] = {2, 8, 1, 7, 3};

City cityArray[] = {
		City("Los Angeles", 4000000),
		City("San Diego", 1500000),
		City("San Francisco", 900000),
		City("Sacramento", 500000),
		City("Stockton", 300000)
};

list<int> intList;
list<City> cityList;

template <typename T>
void initList(list<T> &elementList, T elementArray[], int size) {
	//elementList.resize(size); //TODO Can I remove?
	for (int x = 0; x < size; x++) {
		elementList.push_back(elementArray[x]);
	}
}

template <typename T>
void printList(const list<T> elementList) {
	int a = 0;
	for (T element : elementList) {
		cout << element;
		if (a != elementList.size() - 1)
			cout << " ";
		a++;
	}
	cout << endl << endl;
}

void printCityList(const list<City> cityList) {
	for (City cities : cityList) {
		cities.printInfo();
	}
	cout << endl;
}

template <typename T>
void rotateListRight(list<T> &listToRotate, int n) {
	for (int x = 0; x < n; x++) {
		T lastElement = listToRotate.back();
		listToRotate.pop_back();
		listToRotate.push_front(lastElement);
	}
}

template <typename T>
void rotateListLeft(list<T> &listToRotate, int n) {
	for (int x = 0; x < n; x++) {
		T firstElement = listToRotate.front();
		listToRotate.pop_front();
		listToRotate.push_back(firstElement);
	}
}

void removeFromCityList(list<City> &listToChange, string name) {
	list<City>::iterator iter;
	for (iter = cityList.begin(); iter != cityList.end(); iter++) {

		City c = *iter;

		if (c.getName().compare(name) == 0) {
			listToChange.erase(iter);
			break;
		}

	}
}

void InsertToCityList(list<City> &cityList, City cityToAdd, string name) {
	list<City>::iterator iter;
	for (iter = cityList.begin(); iter != cityList.end(); ++iter) {
		City c = *iter;
		if (c.getName().compare(name) == 0) {
			cityList.insert(iter, cityToAdd);
			break;
		}
	}
}

int main() {

	cout << "Initializing intList with a[]:" << endl;
	initList(intList, a, 5);
	printList(intList);

	cout << "Initializing cityList with cityArray[]:" << endl;
	initList(cityList, cityArray, 5);
	printCityList(cityList);

	cout << "Rotating intList to right twice:" << endl;
	rotateListRight(intList, 2);
	printList(intList);

	cout << "Rotating cityList to right once: " << endl;
	rotateListRight(cityList, 1);
	printCityList(cityList);

	cout << "Rotating intList to left once: " << endl;
	rotateListLeft(intList, 1);
	printList(intList);

	cout << "Rotating cityList to left twice: " << endl;
	rotateListLeft(cityList, 2);
	printCityList(cityList);

	cout << "Removing Sacramento from cityList:" << endl;
	removeFromCityList(cityList, "Sacramento");
	printCityList(cityList);

	cout << "Inserting Redding to cityList before Stockton:" << endl;
	InsertToCityList(cityList, City("Redding", 90000), "Stockton");
	printCityList(cityList);

	return 0;
}