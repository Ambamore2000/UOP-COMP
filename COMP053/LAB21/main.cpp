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

int gaps[] = {4, 2, 1};

void initVector(vector<City> &vectorInput, const City arrayInput[], const int size) {
	for (int x = 0; x < size; x++) { vectorInput.push_back(arrayInput[x]); }
}

void printCityVector(const vector<City> vectorInput) {
	for (City c : vectorInput) c.printInfo();
	cout << endl << endl;
}

/*
InsertionSortInterleaved(numbers, numbersSize, startIndex, gap) {
   i = 0
   j = 0
   temp = 0  // Temporary variable for swap

   for (i = startIndex + gap; i < numbersSize; i = i + gap) {
      j = i
      while (j - gap >= startIndex && numbers[j] < numbers[j - gap]) {
         temp = numbers[j]
         numbers[j] = numbers[j - gap]
         numbers[j - gap] = temp
         j = j - gap
      }
   }
}
 */
void cityInterleavedInsertionSort(vector<City> &inputVector, const int startIndex, const int gap) {
	int i = 0;
	int j = 0;

	for (i = startIndex + gap; i < inputVector.size(); i = i + gap) {
		j = i;
		while (j - gap >= startIndex && inputVector.at(j-gap) > inputVector.at(j)) {
			City temp = inputVector.at(j);
			inputVector.at(j) = inputVector.at(j-gap);
			inputVector.at(j-gap) = temp;
			j = j - gap;
		}
	}
}
/*
ShellSort(numbers, numbersSize, gapValues) {
   for each (gapValue in gapValues) {
      for (i = 0; i < gapValue; i++) {
         InsertionSortInterleaved(numbers, numbersSize, i, gapValue)
      }
   }
}
 */
void cityShellSort(vector<City> &inputVector, const int inputArray[], const int arraySize) {
	for (int x = 0; x < arraySize; x++) {
		int gapValue = inputArray[x];
		for (int i = 0; i < gapValue; i++) {
			cityInterleavedInsertionSort(inputVector, i, gapValue);
		}
	}
}



int main() {

	cout << "Initializing cityVector with cityArray[]:" << endl;
	initVector(cityVector, cityArray, 11);
	printCityVector(cityVector);

	cout << "Shell sort on cityVector" << endl;
	cityShellSort(cityVector,gaps,3);
	printCityVector(cityVector);

	return 0;
}