#include <iostream>
#include <vector>

using namespace std;

int a[] = {5, 7, -2, 8, 11, -9, 4, 6, 12, -1};
vector<int> vec1;

void initVector(vector<int> &vec, int arr[], int size) {
	vec.resize(size);
	int i = 0;
	for (int &x : vec) {
		x = arr[i];
		i++;
	}
}

void printVector(const vector<int> vec) {
	int i = 0;
	for (int x : vec) {
		cout << x;
		if (i != vec.size() - 1)
			cout << ", ";
		i++;
	}
	cout << endl;
}

int minVector(const vector<int> vec) {
	int min = vec.at(0);
	for (int x : vec) {
		if (x < min)
			min = x;
	}
	return min;
}

int productVector(const vector<int> vec) {
	int product = 1;
	for (int x : vec) {
		product = product * x;
	}
	return product;
}

void doubleVector(vector<int> &vec) {
	for (int &x : vec) {
		x = 2*x;
	}
}

void aggregationVector(vector<int> &vec) {
	int summation = 0;
	for (int &x : vec) {
		x = x + summation;
		summation = x;
	}
}

int main() {

	cout << "vec1 content: ";
	initVector(vec1, a, 10);
	printVector(vec1);

	cout << "minimum of vec1: " << minVector(vec1) << endl;

	cout << "product of vec1: " << productVector(vec1) << endl;

	cout << "doubling each element of vec1: ";
	doubleVector(vec1);
	printVector(vec1);

	cout << "aggregating element values in vec1: ";
	aggregationVector(vec1);
	printVector(vec1);

	return 0;
}