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

/*
Merge(numbers, i, j, k) {
   mergedSize = k - i + 1                // Size of merged partition
   mergePos = 0                          // Position to insert merged number
   leftPos = 0                           // Position of elements in left partition
   rightPos = 0                          // Position of elements in right partition
   mergedNumbers = new int[mergedSize]   // Dynamically allocates temporary array
                                         // for merged numbers

   leftPos = i                           // Initialize left partition position
   rightPos = j + 1                      // Initialize right partition position

   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= j && rightPos <= k) {
      if (numbers[leftPos] <= numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos]
         ++leftPos
      }
      else {
         mergedNumbers[mergePos] = numbers[rightPos]
         ++rightPos

      }
      ++mergePos
   }

   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= j) {
      mergedNumbers[mergePos] = numbers[leftPos]
      ++leftPos
      ++mergePos
   }

   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= k) {
      mergedNumbers[mergePos] = numbers[rightPos]
      ++rightPos
      ++mergePos
   }

   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      numbers[i + mergePos] = mergedNumbers[mergePos]
   }
}
*/

/*
 *
int mergeCityVector(numbers, i, j, k) {
	mergedSize = k - i + 1;                // Size of merged partition
	mergePos = 0;                          // Position to insert merged number
	leftPos = 0;                           // Position of elements in left partition
	rightPos = 0;                          // Position of elements in right partition
	mergedNumbers = new int[mergedSize];   // Dynamically allocates temporary array
	// for merged numbers

	leftPos = i;                           // Initialize left partition position
	rightPos = j + 1;                      // Initialize right partition position

	// Add smallest element from left or right partition to merged numbers
	while (leftPos <= j && rightPos <= k) {
		if (numbers[leftPos] <= numbers[rightPos]) {
			mergedNumbers[mergePos] = numbers[leftPos];
			++leftPos;
		} else {
			mergedNumbers[mergePos] = numbers[rightPos];
			++rightPos;
		}
	++mergePos;
	}

	// If left partition is not empty, add remaining elements to merged numbers
	while (leftPos <= j) {
		mergedNumbers[mergePos] = numbers[leftPos];
		++leftPos;
		++mergePos;
	}

	// If right partition is not empty, add remaining elements to merged numbers
	while (rightPos <= k) {
		mergedNumbers[mergePos] = numbers[rightPos];
		++rightPos;
		++mergePos;
	}

	// Copy merge number back to numbers
	for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
		numbers[i + mergePos] = mergedNumbers[mergePos];
	}
}
 */

void mergeCityVector(vector<City> &inputVector, int i, int j, int k) {
	int mergedSize = k - i + 1;                // Size of merged partition
	int mergePos = 0;                          // Position to insert merged number
	int leftPos = 0;                           // Position of elements in left partition
	int rightPos = 0;                          // Position of elements in right partition

	//vector<City> mergedCities;
	//mergedCities.resize(mergedSize);
	City *mergedCities = new City[mergedSize];   // Dynamically allocates temporary array
	//mergedNumbers = new int[mergedSize];
	// for merged numbers

	leftPos = i;                           // Initialize left partition position
	rightPos = j + 1;                      // Initialize right partition position

	// Add smallest element from left or right partition to merged numbers
	while (leftPos <= j && rightPos <= k) {
		if (inputVector.at(leftPos).getPopulation() <= inputVector.at(rightPos).getPopulation()) {
			mergedCities[mergePos] = inputVector.at(leftPos);
			++leftPos;
		} else {
			mergedCities[mergePos] = inputVector.at(rightPos);
			++rightPos;
		}
		++mergePos;
	}

	// If left partition is not empty, add remaining elements to merged numbers
	while (leftPos <= j) {
		mergedCities[mergePos] = inputVector.at(leftPos);
		++leftPos;
		++mergePos;
	}

	// If right partition is not empty, add remaining elements to merged numbers
	while (rightPos <= k) {
		mergedCities[mergePos] = inputVector.at(rightPos);
		++rightPos;
		++mergePos;
	}

	// Copy merge number back to numbers
	for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
		inputVector.at(i + mergePos) = mergedCities[mergePos];
	}
}

/*
MergeSort(numbers, i, k) {
   j = 0

   if (i < k) {
      j = (i + k) / 2  // Find the midpoint in the partition

      // Recursively sort left and right partitions
      MergeSort(numbers, i, j)
      MergeSort(numbers, j + 1, k)

      // Merge left and right partition in sorted order
      Merge(numbers, i, j, k)
   }
}
 */

void cityMergeSort(vector<City> &inputVector, int i, int k) {
	int j = 0;

	if (i < k) {
		j = (i + k) / 2;  // Find the midpoint in the partition

		// Recursively sort left and right partitions
		cityMergeSort(inputVector, i, j);
		cityMergeSort(inputVector, j + 1, k);

		// Merge left and right partition in sorted order
		mergeCityVector(inputVector, i, j, k);
	}
}

int main() {

	cout << "Initializing cityVector with cityArray[]:" << endl;
	initVector(cityVector, cityArray, 11);
	printCityVector(cityVector);

	cout << "Merge sort on cityVector" << endl;
	cityMergeSort(cityVector, 0, cityVector.size() - 1);
	printCityVector(cityVector);

	return 0;
}