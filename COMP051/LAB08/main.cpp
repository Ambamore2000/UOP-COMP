#include <iostream>

#include <fstream>
#include <string>

using namespace std;

void getData(bool isNewFile) {
    string fileName;
    cout << "Please enter filename: ";
    cin >> fileName;

    ofstream outputStream;

    if (isNewFile)
        outputStream.open(fileName);
    else
        outputStream.open(fileName, ios::app);

    int amountOfStudents;
    cout << "How many students will you be entering data for: ";
    cin >> amountOfStudents;
    while (cin.fail() || amountOfStudents < 1) {
        cin.clear();
        cin.ignore(128, '\n');
        cout << "ERROR: Please enter an integer greater than or equal to 1." << endl;
        cin >> amountOfStudents;
    }

    for (int i = 0; i < amountOfStudents; i++) {
        string birthMonth, examScore;

        cout << "Student's Birth Month: ";
        cin >> birthMonth;

        cout << "Student's Exam Score: ";
        cin >> examScore;

        outputStream << birthMonth << " " << examScore << endl;
    }
    outputStream.close();
}

void createNewFile() {
    getData(true);
}

void appendToExisting() {
    getData(false);
}

void analyzeData() {
    string fileName;
    cout << "Please enter filename: ";
    cin >> fileName;

    ifstream inputStream;

    inputStream.open(R"(C:\Users\Andki\CLionProjects\COMP51_Andrew_Kim_Lab_Eigth\cmake-build-debug\)" + fileName);

    if (inputStream.fail()) {
        cout << "ERROR: Invalid file." << endl;
        return;
    }

    int amountOfJulyStudents = 0;
    int amountOfNonJulyStudents = 0;
    int sumOfJulyScores = 0;
    int sumOfNonJulyScores = 0;

    string birthMonth;
    int examScore;

    while (inputStream >> birthMonth >> examScore) {
        if (birthMonth == "July") {
            sumOfJulyScores = sumOfJulyScores + examScore;
            amountOfJulyStudents++;
        } else {
            sumOfNonJulyScores = sumOfNonJulyScores + examScore;
            amountOfNonJulyStudents++;
        }
    }

    inputStream.close();

    int avgJuly = (sumOfJulyScores/amountOfJulyStudents);
    int avgOthers = (sumOfNonJulyScores/amountOfNonJulyStudents);

    if (avgJuly <  avgOthers)
        cout << "Time for a new theory Doctor!" << endl;
    else
        cout << "Wow.. You're right Doctor!" << endl;

    cout << "Avg. Score for July Students: " << avgJuly << endl;
    cout << "Avg. Score for Other Students: " << avgOthers << endl;
}


int main() {
    int option;

    do {
        cout << "1. Create new data file" << endl;
        cout << "2. Append to existing data file" << endl;
        cout << "3. Analyze data" << endl;
        cout << "4. Quit" << endl;
        cout << "Please select a menu option: ";
        cin >> option;

        while (cin.fail() || option > 4 || option < 1) {
            cout << "ERROR: Invalid option. Please enter an integer between 1-4.";
            cin >> option;
        }

        switch(option) {
            case 1:
                createNewFile();
                break;
            case 2:
                appendToExisting();
                break;
            case 3:
                analyzeData();
                break;
        }
    } while (option != 4);

    system("PAUSE");

    return 0;
}