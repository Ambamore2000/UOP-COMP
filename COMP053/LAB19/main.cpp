#include <iostream>
#include <vector>
#include "city.h"
#include <algorithm>

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

int steps = 0;


void initVector(vector<City> &vectorInput, const City arrayInput[], const int size) {
	for (int x = 0; x < size; x++) { vectorInput.push_back(arrayInput[x]); }
}

void printCityVector(const vector<City> vectorInput) {
	for (City c : vectorInput) c.printInfo();
	cout << endl << endl;
}

bool compareCities(const City firstCity, const City secondCity) {
	return firstCity < secondCity;
}

/*
LinearSearch(numbers, int numbersSize, int key) {
   i = 0

   for (i = 0; i < numbersSize; ++i) {
      if (numbers[i] == key) {
         return i
      }
   }

   return -1 // not found
}
 */
unsigned int cityLinearSearch(const vector<City> vectorInput, const string stringInput) {
	for (int i = 0; i < vectorInput.size(); i++) {
		steps++;
		if (vectorInput.at(i).getName() == stringInput)
			return vectorInput.at(i).getPopulation();
	}
	return 0;
}

/*
BinarySearch(numbers, numbersSize, key) {
   mid = 0
   low = 0
   high = numbersSize - 1

   while (high >= low) {
      mid = (high + low) / 2
      if (numbers[mid] < key) {
         low = mid + 1
      }
      else if (numbers[mid] > key) {
         high = mid - 1
      }
      else {
         return mid
      }
   }

   return -1 // not found
}
 */

unsigned int cityBinarySearch(const vector<City> vectorInput, const string stringInput) {
	int mid = 0, low = 0, high = vectorInput.size()-1;

	while (high >= low) {
		steps++;
		mid = (high + low) / 2;
		if (vectorInput.at(mid).getName() < stringInput) {
			low = mid + 1;
		} else if (vectorInput.at(mid).getName() > stringInput) {
			high = mid - 1;
		} else if (vectorInput.at(mid).getName() == stringInput) {
			return vectorInput.at(mid).getPopulation();
		}
	}
	return 0;
}

int main() {

	cout << "Initializing cityVector with cityArray[]:" << endl;
	initVector(cityVector,cityArray,11);
	printCityVector(cityVector);


	cout << "Sorting cityVector based on names in ascending order:" << endl;
	sort(cityVector.begin(), cityVector.end(), compareCities);
	printCityVector(cityVector);

	cout << "Linear search for the population of San Francisco: ";
	cout << cityLinearSearch(cityVector, "San Francisco") << endl;
	cout << "Number of comparisons for this search: " << steps << endl << endl;
	steps = 0;

	cout << "Linear search for the population of Boston: ";
	cout << cityLinearSearch(cityVector, "Boston") << endl;
	cout << "Number of comparisons for this search: " << steps << endl << endl;
	steps = 0;

	cout << "Binary search for the population of San Francisco: ";
	cout << cityBinarySearch(cityVector, "San Francisco") << endl;
	cout << "Number of comparisons for this search: " << steps << endl << endl;

	steps = 0;
	cout << "Binary search for the population of Boston: ";
	cout << cityBinarySearch(cityVector, "Boston") << endl;
	cout << "Number of comparisons for this search: " << steps << endl << endl;
	steps = 0;

	return 0;
}