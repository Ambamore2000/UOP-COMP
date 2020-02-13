#include <iostream>
#include <vector>

using namespace std;

const int ASIZE = 5;
const int STRSIZE = 7;

int a[] = {6, 10, -4, 11, -2};
char str[STRSIZE] = "Hello.";
vector<int> vec1;
vector<char> vec2;



template<typename arrType>
void reverseArray(arrType arr[], int size) {
	size--;
	for (int x = 0; x < (size) / 2; x++) {
		arrType temp = arr[size - x];
		arr[size - x] = arr[x];
		arr[x] = temp;
	}
}

template<typename arrType>
void printArray(arrType arr[], int size) {
	for (int x = 0; x < size; x++) {
		cout << arr[x];
		if (x != size - 1)
			cout << ", ";
	}
	cout << endl << endl;
}

template<typename type>
void initVector(vector<type> &vec, type arr[], int size) {
	vec.resize(size);
	for (int x = 0; x < size; x++) {
		vec.at(x) = arr[x];
	}
}

template<typename vecType>
void replaceLastThree(vector<vecType> &vec, vecType item1, vecType item2, vecType item3) {
	vec.pop_back();
	vec.pop_back();
	vec.pop_back();

	vec.push_back(item1);
	vec.push_back(item2);
	vec.push_back(item3);
}

template<typename vecType>
void printVector(vector<vecType> vec) {
	for (int x = 0; x < vec.size(); x++) {
		cout << vec.at(x);
		if (x != vec.size() - 1)
			cout << ", ";
	}
	cout << endl << endl;
}

template<typename CompObj>
class Comparable {
private:
	CompObj item1, item2;
public:
	bool lt() {
		return item1 < item2;
	}
	bool gt() {
		return item1 > item2;
	}
	bool eq() {
		return item1 == item2;
	}
	Comparable(CompObj item1, CompObj item2) {
		this->item1 = item1;
		this->item2 = item2;
	}
};

int main() {


	cout << "Reverse a[]:" << endl;
	reverseArray(a, ASIZE);
	printArray(a, ASIZE);

	cout << "Reverse str[]:" << endl;
	reverseArray(str, STRSIZE);
	printArray(str, STRSIZE);

	cout << "Initialize vec1 according to a[]:" << endl;
	initVector(vec1, a, ASIZE);
	printVector(vec1);

	cout << "Initialize vec2 according to str[]:" << endl;
	initVector(vec2, str, STRSIZE);
	printVector(vec2);

	replaceLastThree(vec1, 9, 0, 2);
	cout << "Replace last three elements of vec1 with 9, 0, and 2:" << endl;
	printVector(vec1);

	replaceLastThree(vec2, 'f', 'y', 'o');
	cout << "Replace last three elements of vec2 with 'f', 'y', and 'o':" << endl;
	printVector(vec2);

	Comparable<int> comp1(3, 5);
	Comparable<char> comp2('r', 'b');

	cout << "Is 1st component of comp1 less than 2nd component of it? " << comp1.lt() << endl;

	cout << "Is 1st component of comp2 equal to 2nd component of it? " << comp2.eq() << endl;

	return 0;
}