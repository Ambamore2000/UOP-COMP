#include <iostream>

const int SIZE = 10;

int a[SIZE] = {5,7,-2,8,11,-9,4,6,12,-1};
int b[SIZE] = {4,16,9,-2,1,14,-4,8,10,0};
int c[SIZE];

using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i != size - 1)
            cout << ", ";
    }
    cout << endl;
}

int minArray(int arr[], const int size) {
    int minValue = 9999;
    for (int i = 0; i < size; i++) {
        if (arr[i] < minValue)
            minValue = arr[i];
    }
    return minValue;
}

int maxArray(int arr[], int size) {
    int maxValue = -9999;
    for (int i = 0; i < size; i++) {
        if (arr[i] > maxValue)
            maxValue = arr[i];
    }
    return maxValue;
}

int sumArray(int arr[], int size) {
    int sumValue = 0;
    for (int i = 0; i < size; i++) {
        sumValue += arr[i];
    }
    return sumValue;
}

int productArray(int arr[], int size) {
    int prodValue = 1;
    for (int i = 0; i < size; i++) {
        prodValue = prodValue * arr[i];
    }
    return prodValue;
}

void copyArray(int arrNewCopy[], int arrToCopy[], int size) {
    for (int i = 0; i < size; i++) {
        arrNewCopy[i] = arrToCopy[i];
    }
}

void greaterArray(int arrNewCopy[], int arrCompOne[], int arrCompTwo[], int size) {

    for (int i = 0; i < size; i++) {
        if (arrCompOne[i] > arrCompTwo[i])
            arrNewCopy[i] = arrCompOne[i];
        else
            arrNewCopy[i] = arrCompTwo[i];
    }
}


int main() {

    cout << "minimum of a[]: " << minArray(a, SIZE) << endl;
    cout << "maximum of a[]: " << maxArray(a, SIZE) << endl;
    cout << "sum of a[]: " << sumArray(a, SIZE) << endl;
    cout << "product of a[]: " << productArray(a, SIZE) << endl;
    copyArray(c, a, SIZE);
    cout << "copy a[] to c[]: ";
    printArray(c, SIZE);

    cout << "collect larger elements from a[] and b[] to c[]: ";
    greaterArray(c, a, b, SIZE);
    printArray(c,SIZE);
    return 0;
}