#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>

#include "city.h"

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

vector<City> cityVector;

vector<unsigned int> popVector;

void initVector(vector<City> &vectorInput, const City arrayInput[], const int size) {
	for (int x = 0; x < size; x++) { vectorInput.push_back(arrayInput[x]); }
}

void printCityVector(const vector<City> vectorInput) {
	for (City c : vectorInput) c.printInfo();
	cout << endl << endl;
}

template <typename T>
void printVector(const vector<T> vectorInput) {
	for (auto c : vectorInput) cout << c << " ";
	cout << endl << endl;
}

void populationProject(const vector<City> cityVectorInput, vector<unsigned int> &popVectorInput) {
	for (City c : cityVectorInput) popVectorInput.push_back(c.getPopulation());
}

/*
// Returns the maximum length, in number of digits, out of all elements in the array
RadixGetMaxLength(array, arraySize) {
   maxDigits = 0
   for (i = 0; i < arraySize; i++) {
      digitCount = RadixGetLength(array[i])
      if (digitCount > maxDigits)
         maxDigits = digitCount
   }
   return maxDigits
}
*/

int radixGetLength(unsigned int value) {
	if (value == 0)
		return 1;

	int digits = 0;
	while (value != 0) {
		digits = digits + 1;
		value = value / 10;
	}
	return digits;
}

int radixGetMaxLength(vector<unsigned int> popVectorInput) {
	int maxDigits = 0;
	for (int i = 0; i < popVectorInput.size(); i++) {
		int digitCount = radixGetLength(popVectorInput.at(i));
		if (digitCount > maxDigits)
			maxDigits = digitCount;
	}
	return maxDigits;
}

/*
// Returns the length, in number of digits, of value
RadixGetLength(value) {
   if (value == 0)
      return 1

   digits = 0
   while (value != 0) {
      digits = digits + 1
      value = value / 10
   }
   return digits
}
 */


/*
RadixSort(array, arraySize) {
   buckets = create array of 10 buckets

   // Find the max length, in number of digits
   maxDigits = RadixGetMaxLength(array, arraySize)

   // Start with the least significant digit
   pow10 = 1
   for (digitIndex = 0; digitIndex < maxDigits; digitIndex++) {
      for (i = 0; i < arraySize; i++) {
         bucketIndex = abs(array[i] / pow10) % 10
         Append array[i] to buckets[bucketIndex]
      }
      arrayIndex = 0
      for (i = 0; i < 10; i++) {
         for (j = 0; j < buckets[i].size(); j++)
            array[arrayIndex++] = buckets[i][j]
      }
      pow10 = 10 * pow10
      Clear all buckets
   }
}
 */

void populationRadixSort(vector<unsigned int> &popVectorInput) {
	list<unsigned int> bucket[10];

	// Find the max length, in number of digits
	int maxDigits = radixGetMaxLength(popVectorInput);

	// Start with the least significant digit
	int pow10 = 1;
	for (int digitIndex = 0; digitIndex < maxDigits; digitIndex++) {
		for (int i = 0; i < popVectorInput.size(); i++) {
			int bucketIndex = (popVectorInput.at(i) / pow10) % 10;
			bucket[bucketIndex].push_back(popVectorInput.at(i));
		}

		int arrayIndex = 0;
		for (int i = 0; i < 10; i++) {
			for (int j : bucket[i]) {
				popVectorInput.at(arrayIndex++) = j;
			}
		}

		pow10 = 10 * pow10;

		for (int i = 0; i < 10; i++) {
			bucket[i].clear();
		}
	}
}

int main() {

	cout << "Initializing cityVector with cityArray[]:" << endl;
	initVector(cityVector, cityArray, 11);
	printCityVector(cityVector);

	cout << "Initialize popVector according to cityVector:" << endl;
	populationProject(cityVector, popVector);
	printVector(popVector);

	cout << "Radix sort on popVector:" << endl;
	populationRadixSort(popVector);
	printVector(popVector);

	return 0;
}