#include <iostream>

#include <string>
#include "cities.h"

using namespace std;

class State {

public:
    State() { name = "N/A"; }
    void setName(string stateName) { name = stateName; }
    string getName() const { return name; }

    void readStateCities() { stateCities.readCities(); }
    void printStateCities() { stateCities.printCityList(); }
private:
    string name;

    Cities stateCities;
};

int main() {

    string userStateName;

    cout << "State: ";
    cin >> userStateName;

    State userState;
    userState.setName(userStateName);

    cout << "Enter city name and population. To end, enter X." << endl;

    userState.readStateCities();

    cout << "The state " << userState.getName() << " has the following cities/populations:" << endl;

    userState.printStateCities();

    return 0;
}

