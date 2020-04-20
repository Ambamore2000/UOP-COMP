/////////////////////////////////////
///////Change Making Program/////////
///////////By: Andrew Kim////////////
/////////////////////////////////////
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Prompt user name
	string operationInput = "Z";
	cout << "Welcome to my calculator!" << endl << endl
		<< "Please select an operation from the following list:" << endl;
	do {
		cout << "<A>dd" << endl;
		cout << "<S>ubtract" << endl;
		cout << "<M>ultiply" << endl;
		cout << "<D>ivide" << endl;
		cout << "<C>ompare" << endl;
		cout << "<R>andom" << endl;
		cout << "<Q>uit" << endl;
		cout << "S<T>ar" << endl;

		cin >> operationInput;

		if (operationInput == "q" || operationInput == "Q")
			break;

		if (operationInput == "R" || operationInput == "r") {
			cout << rand() % 4 + 13 << endl;
			cout << rand() % 4 + 13 << endl;
			cout << rand() % 4 + 13 << endl;
			cout << rand() % 4 + 13 << endl;
			cout << rand() % 4 + 13 << endl;
		}

		if (operationInput == "T" || operationInput == "t") {
			double numberOne;
			cout << "Please enter the number of stars to display" << endl;
			do {
				cin >> numberOne;
				while (numberOne > 0) { 
					cout << "*";
					numberOne--;
				}
				cout << endl;
				break;
			} while (numberOne < 0);
			continue;
		}

		double numberOne, numberTwo;
		cout << "Please enter two numbers: ";
		cin >> numberOne;
		cin >> numberTwo;

		string operation = "";
		double math = -1;

		if (operationInput == "C" || operationInput == "c") {
			string isGreater = "is ";
			if (numberOne < numberTwo)
				isGreater = isGreater + "not ";
			cout << numberOne << " " << isGreater << "greater than " << numberTwo << endl;
			continue;
		}
		else if (operationInput == "R" || operationInput == "r") {
			cout << rand() % (int)(numberTwo - numberOne + 1) + numberOne << endl;
			cout << rand() % (int)(numberTwo - numberOne + 1) + numberOne << endl;
			cout << rand() % (int)(numberTwo - numberOne + 1) + numberOne << endl;
			cout << rand() % (int)(numberTwo - numberOne + 1) + numberOne << endl;
			cout << rand() % (int)(numberTwo - numberOne + 1) + numberOne << endl;
			continue;
		}

		if (operationInput == "A" || operationInput == "a") {
			operation = "sum";
			math = numberOne + numberTwo;
		}
		else if (operationInput == "S" || operationInput == "s") {
			operation = "difference";
			math = numberOne - numberTwo;
		}
		else if (operationInput == "M" || operationInput == "m") {
			operation = "product";
			math = numberOne * numberTwo;
		}
		else if (operationInput == "D" || operationInput == "d") {
			do {
				cout << "ERROR: Answer undefined (Divided by 0!)" << endl
					<< "Enter a divisor that is not 0!" << endl;
				cin >> numberTwo;
			} while (numberTwo == 0);

			operation = "quotient";
			math = (numberOne / numberTwo);
		}

		cout << "The " << operation << " is " << math << endl;
		
	} while (operationInput != "Q" && operationInput != "q");
}