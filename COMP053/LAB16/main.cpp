#include <iostream>

#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include "city.h"

City cityArray[] = {
		City("Los Angeles", 4000000),
		City("San Diego", 1500000),
		City("San Fransisco", 900000),
		City("Sacramento", 500000),
		City("Stockton", 300000)
};

queue<City> cityQueue;
deque<City> cityStack;
vector<City> cityVector;

void initQueue(queue<City> &inputQueue, const City inputArray[], const int size) {
	for (int x = 0; x < size; x++) { inputQueue.push(inputArray[x]); }
}
void printCityQueue(queue<City> inputQueue) {
	for (int x = 0; x < inputQueue.size(); x++) {
		inputQueue.front().printInfo();
		inputQueue.push(inputQueue.front());
		inputQueue.pop();
	}
	cout << endl;
}

void initStack(deque<City> &inputDeque, const City inputArray[], const int size) {
	for (int x = 0; x < size; x++) { inputDeque.push_front(inputArray[x]); }
}

void printCityStack(deque<City> &inputDeque) {
	deque<City> dequeStack;
	for (int x = 0; x < inputDeque.size(); x++) {
		inputDeque.front().printInfo();
		dequeStack.push_front(inputDeque.front());
		inputDeque.pop_front();

		inputDeque.push_back(dequeStack.front());
		dequeStack.pop_front();
	}
	cout << endl;
}

void initVector(vector<City> &inputVector, const City inputArray[], const int size) {
	for (int x = 0; x < size; x++) { inputVector.push_back(inputArray[x]); }
}

void printCityVector(const vector<City> inputVector) {
	for (City c : inputVector) { c.printInfo(); }
	cout << endl;
}

bool greaterName(const City firstInput, const City secondInput) {
	return secondInput < firstInput;
}

bool greaterPop(const City firstInput, const City secondInput) {
	return secondInput > firstInput;
}

int main() {

	cout << "Initializing cityQueue with cityArray[]:" << endl;
	initQueue(cityQueue, cityArray, 5);
	printCityQueue(cityQueue);

	cout << "Initializing cityStack with cityArray[]:" << endl;
	initStack(cityStack, cityArray, 5);
	printCityStack(cityStack);

	cout << "Initializing cityVector  with cityArray[]:" << endl;
	initVector(cityVector, cityArray, 5);
	printCityVector(cityVector);

	cout << "Sorting cityVector based on names in descending order: " << endl;
	sort(cityVector.begin(), cityVector.end(), greaterName);
	printCityVector(cityVector);

	cout << "Sorting cityVector based on populations in ascending order: " << endl;
	sort(cityVector.begin(), cityVector.end(), greaterPop);
	printCityVector(cityVector);

	return 0;
}