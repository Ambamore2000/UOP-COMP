#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    double initialBalance, interestRate, preminRate, premaxRate, minRate, maxRate;
    int years;
    int i;
    double x;
    double newBalance;

    cout << "Welcome to Andrews Balance Calculator!" << endl;
    cout << "Please enter your initial balance: $";
    cin >> initialBalance;
    newBalance = initialBalance;
    cout << "Please enter the interest rate: ";
    cin >> interestRate;
    cout << "Please enter the number of years you plan to save: ";
    cin >> years;

    for (i = 1; i <= years; i++) {
        newBalance = newBalance * (1 + interestRate / 100.0);
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "Your balance after " << years << " years will be $" << newBalance << "." << endl;

    cout << "Let's see how different interest rates affect your balance after one year ..." << endl;
    cout << "Please enter the min and max interest rates: ";
    cin >> preminRate >> premaxRate;
    if (preminRate < premaxRate) {
        maxRate = premaxRate;
        minRate = preminRate;
    }
    else {
        maxRate = preminRate;
        minRate = premaxRate;
    }

    for (x = minRate; x <= maxRate; x += 0.5) {
        newBalance = initialBalance * (1 + x / 100.0);
        cout << setw(6) << x << ": $" << newBalance << endl;
    }

    system("pause");
}