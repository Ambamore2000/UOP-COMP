#include <iostream>
#include <vector>
#include "city.h"

City cityArray[] = {
		City("Los Angeles",4000000),
		City("San Diego",1500000),
		City("San Francisco",900000),
		City("Sacramento",500000),
		City("Stockton",300000),
		City("Redding",90000),
		City("Las Vegas",700000),
		City("Reno",300000),
		City("Portland",700000),
		City("Seattle",750000),
		City("Eugene",200000)
};

vector<City> cityVector;

void initVector(vector<City> &vectorInput, const City arrayInput[], const int size) {
	for (int x = 0; x < size; x++) { vectorInput.push_back(arrayInput[x]); }
}

void printCityVector(const vector<City> vectorInput) {
	for (City c : vectorInput) c.printInfo();
	cout << endl << endl;
}

void citySelectionSort(vector<City> &vectorInput) {
	int i = 0;
	int j = 0;
	int indexSmallest = 0;

	for (i = 0; i < vectorInput.size() - 1; ++i) {

		indexSmallest = i;
		for (j = i + 1; j < vectorInput.size(); ++j) {

			if ( vectorInput.at(j).getPopulation() < vectorInput.at(indexSmallest).getPopulation() ) {
				indexSmallest = j;
			}
		}

		City temp = vectorInput.at(i);
		vectorInput.at(i) = vectorInput.at(indexSmallest);
		vectorInput.at(indexSmallest) = temp;
	}
}

void cityInsertionSort(vector<City> &vectorInput) {

	int i = 0;
	int j = 0;

	for (i = 1; i < vectorInput.size(); ++i) {
		j = i;

		while (j > 0 && vectorInput.at(j).getPopulation() < vectorInput.at(j - 1).getPopulation()) {

			City temp = vectorInput.at(j);
			vectorInput.at(j) = vectorInput.at(j - 1);
			vectorInput.at(j - 1) = temp;
			--j;

		}
	}
}

int main() {

	cout << "Initializing cityVector with cityArray[]:" << endl;
	initVector(cityVector, cityArray, 11);
	printCityVector(cityVector);

	cout << "Selection sort on cityVector:" << endl;
	citySelectionSort(cityVector);
	printCityVector(cityVector);

	cout << "Re-initializing cityVector with cityArray[]:" << endl;
	cityVector.clear();
	initVector(cityVector, cityArray, 11);
	printCityVector(cityVector);

	cout << "Insertion sort on cityVector:" << endl;
	cityInsertionSort(cityVector);
	printCityVector(cityVector);

	return 0;
}