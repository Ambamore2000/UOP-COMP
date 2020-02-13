#include <iostream>

using namespace std;

void find (char d[], int size, char c) {
    bool foundPosition = false;
    for (int x = 0; x < size; x++) {
        if (c == d[x]) {
            cout << "Found " << c << " at position " << x << "." << endl;
            foundPosition = true;
        }
    }
    if (!foundPosition)
        cout << "Character Array does NOT contain '" << c << "'!" << endl;
}
int main() {

    //#1
    char letters[8];

    //#2
    for (int x = 0; x < sizeof(letters); x++) {
        cout << "Please enter letter #" << x << ": ";
        cin >> letters[x];
    }

    //#3
    cout << endl << "The word is ";

    for (int x = 0; x < sizeof(letters); x++) {
        cout << letters[x];
    }

    //#4
    cout << endl << "The word backwards is ";

    for (int x = sizeof(letters) - 1; x >= 0; x--) {
        cout << letters[x];
    }

    //#b
    char searchChar;

    cout << endl << "What letter would you like to search for? ";
    cin >> searchChar;

    find(letters, sizeof(letters), searchChar);

    system("PAUSE");
    return 0;
}