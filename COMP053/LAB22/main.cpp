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
Partition(numbers, i, k) {
   l = 0
   h = 0
   midpoint = 0
   pivot = 0
   temp = 0
   done = false

   // Pick middle element as pivot
   midpoint = i + (k - i) / 2
   pivot = numbers[midpoint]

   l = i
   h = k

   while (!done) {

      // Increment l while numbers[l] < pivot
      while (numbers[l] < pivot) {
         ++l
      }

      // Decrement h while pivot < numbers[h]
      while (pivot < numbers[h]) {
         --h
      }

      // If there are zero or one elements remaining,
      // all numbers are partitioned. Return h
      if (l >= h) {
         done = true
      }
      else {
         // Swap numbers[l] and numbers[h],
         // update l and h
         temp = numbers[l]
         numbers[l] = numbers[h]
         numbers[h] = temp

         ++l
         --h
      }
   }

   return h
}
*/

int partition(vector<City> &vectorInput, int i, int k) {
	int l = 0;
	int h = 0;
	int midpoint = 0;
	City pivot = City("",0);
	City temp = City("",0);
	bool done = false;

	midpoint = i + (k - i) / 2;
	pivot = vectorInput.at(midpoint);

	l = i;
	h = k;

	while (!done) {
		while (pivot > vectorInput.at(l)) {
			++l;
		}

		while (vectorInput.at(h) > pivot) {
			--h;
		}

		if (l >= h) {
			done = true;
		} else {
			temp = vectorInput.at(l);
			vectorInput.at(l) = vectorInput.at(h);
			vectorInput.at(h) = temp;

			++l;
			--h;
		}
	}

	return h;
}

/*
Quicksort(numbers, i, k) {
   j = 0

   // Base case: If there are 1 or zero elements to sort,
   // partition is already sorted
   if (i >= k) {
      return
   }

   // Partition the data within the array. Value j returned
   // from partitioning is location of last element in low partition.
   j = Partition(numbers, i, k)

   // Recursively sort low partition (i to j) and
   // high partition (j + 1 to k)
   Quicksort(numbers, i, j)
   Quicksort(numbers, j + 1, k)
}
*/
void quicksort(vector<City> &vectorInput, int i, int k) {
	int j = 0;

	if (i >= k) {
		return;
	}

	j = partition(vectorInput, i, k);

	quicksort(vectorInput, i, j);
	quicksort(vectorInput, j + 1, k);
}



int main() {

	cout << "Initializing cityVector with cityArray[]:" << endl;
	initVector(cityVector, cityArray, 11);
	printCityVector(cityVector);

	cout << "Quick sort on cityVector" << endl;
	quicksort(cityVector, 0, cityVector.size() - 1);
	printCityVector(cityVector);

	return 0;
}