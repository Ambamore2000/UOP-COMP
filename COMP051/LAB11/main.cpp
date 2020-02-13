#include <iostream>

#include <stdlib.h>
#include <time.h>

using namespace std;

int sumX(int x) {
    if (x == 0)
        return x; //return x means inclusive..
    else if (x > 0) {
        cout << x << ",";
        return (x + sumX(x - 1));
    } else if (x < 0) {
        return (x + sumX(x + 1));
    }
}

int sumXY(int x, int y) {
    if (x == y)
        return x; // inclusive??
    if (x > y) {
        int temp = x;
        x = y;
        y = temp;
    }
    if (y >= x) {
        return (y + sumXY(x, y - 1));
    }
}

void fillArray(int arr[], int size) {
    if (size > 0) {
        arr[size - 1] = rand() % 11;
        fillArray(arr, size - 1);
    }
}

int main() {

    srand (time(NULL));

    cout << sumX(1) << endl;
    cout << sumX(3) << endl;
    cout << sumX(6) << endl;
    cout << sumX(10) << endl;
    cout << sumXY(1, 5) << endl;
    cout << sumXY(5, 1) << endl;
    cout << sumXY(3, 10) << endl;
    cout << sumXY(10, 3) << endl;
    cout << sumXY(6, 15) << endl;
    cout << sumXY(15, 6) << endl;
    cout << sumXY(10, 20) << endl;
    cout << sumXY(20, 10) << endl;

    int thisArray[5];
    fillArray(thisArray, 5);

    for (int x = 0; x < 5; x++) {
        cout << thisArray[x] << endl;
    }

    return 0;
}