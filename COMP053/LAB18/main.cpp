#include <iostream>

using namespace std;

int aArr[] = {2,8,1,7,3};
int bArr[5];

void printArray(int a[], int size, int index) {
	if (index == size)
		return;
	else {
		cout << a[index] << " ";
		printArray(a,size,index+1);
	}
}

void printReverseArray(int a[], int size, int index) {
	if (index >= size)
		return;
	//else if (index < 0)
	//	return;
	else {
		cout << a[size-1-index] << " ";
		printReverseArray(a, size,index+1);
	}
}

void reverseArray(int a[], int start, int end) {
	if (start <= end)
		return;
	else {
		int temp = a[start-1];
		a[start-1] = a[end];
		a[end] = temp;

		reverseArray(a, start-1, end+1);
	}
}

int sumArray(int a[], int size, int index) {
	if (size-1 == index)
		return a[index];
	else {
		return a[index] + sumArray(a,size,index+1);
	}
}

int productArray(int a[], int size, int index) {
	if (size-1 == index)
		return a[index];
	else {
		return a[index] * productArray(a,size,index+1);
	}
	return -1;
}

void copyArray(int a[], int b[], int size, int index) {
	if (size == index)
		return;
	else {
		b[index] = a[index];
		copyArray(a,b,size,index+1);
	}
}

int minArray(int a[], int size, int index) {
	if (size-1 == index)
		return a[index];
	else if (a[index] < minArray(a, size, index+1))
		return a[index];

}

int maxArray(int a[], int size, int index) {
	if (size-1 == index)
		return a[index];
	else if (a[index] > maxArray(a, size, index+1))
		return a[index];
}

int main() {

	//Recurrence Relation: O(n)
	//A linear algorithm

	cout << "Array a[] content in order:" << endl;
	printArray(aArr,5,0);
	cout << endl << endl;

	cout << "Array a[] content in reverse:" << endl;
	printReverseArray(aArr,5, 0);
	cout << endl << endl;

	cout << "Reversing a[]:" << endl;
	reverseArray(aArr,5,0);
	printArray(aArr,5,0);
	cout << endl << endl;

	cout << "Summation of elements in a[]:" << endl;
	cout << sumArray(aArr,5,0);
	cout << endl << endl;

	cout << "Product of elements in a[]:" << endl;
	cout << productArray(aArr,5,0);
	cout << endl << endl;

	cout << "Copying a[] to b[]:" << endl;
	copyArray(aArr,bArr,5,0);
	printArray(bArr,5,0);
	cout << endl << endl;

	cout << "Minimum element in a[]:" << endl;
	cout << minArray(aArr,5,0);
	cout << endl << endl;

	cout << "Maximum element in a[]:" << endl;
	cout << maxArray(aArr,5,0);
	cout << endl << endl;


	return 0;
}