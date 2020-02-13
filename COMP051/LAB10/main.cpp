#include <iostream>

using namespace std;

class Fraction {
    public:
        Fraction();
        Fraction(int n, int d);

        int getNum();
        int getDen();

        void setNum(int n);
        void setDen(int &d);

        void print();

        double getDecimal();
    private:
        int num, den;
};

Fraction::Fraction() {
    num = 0;
    den = 1;
}
Fraction::Fraction(int n, int d) {
    setNum(n);
    setDen(d);
}

int Fraction::getNum() {
    return num;
}
int Fraction::getDen() {
    return den;
}

void Fraction::setNum(int newNum) {
    num = newNum;
}
void Fraction::setDen(int &newDen) {
    while (newDen == 0) {
        cout << "ERROR: 0 is not a valid denominator." << endl;
        cin.clear();
        cin.ignore(128, '\n');
        cout << "Please enter a new denominator that is not 0." << endl;
        cin >> newDen;
    }
    den = newDen;
}

void Fraction::print() {
    cout << getNum() << "/" << getDen();
}
double Fraction::getDecimal() {
    return (double) getNum()/getDen();
}

int main() {
    cout << "Lab 10: Fractions" << endl;
    Fraction theFrac(6, 10);
    theFrac.print();
    cout << endl;

    Fraction coolFracArray[3];

    for (int x = 0; x < 3; x++) {
        int n, d;
        cout << "Enter numerator of Fraction #" << (x + 1) << ": ";
        cin >> n;
        coolFracArray[x].setNum(n);
        cout << "Enter denominator of Fraction #" << (x + 1) << ": ";
        cin >> d;
        coolFracArray[x].setDen(d);
    }

    Fraction largestNumerator, largestDenominator, largestDecimal;

    for (int x = 0; x < 3; x++) {
        if (coolFracArray[x].getNum() > largestNumerator.getNum())
            largestNumerator = coolFracArray[x];
        if (coolFracArray[x].getDen() > largestDenominator.getDen())
            largestDenominator = coolFracArray[x];
        if (coolFracArray[x].getDecimal() > largestDecimal.getDecimal())
            largestDecimal = coolFracArray[x];
    }
    cout << "Largest Numerator Fraction: ";
    largestNumerator.print();
    cout << endl << "Numerator Value: " << largestNumerator.getNum() << endl;
    cout << "Largest Denominator Fraction: ";
    largestDenominator.print();
    cout << endl << "Denominator Value: " << largestDenominator.getDen() << endl;
    cout << "Largest Decimal Fraction: ";
    largestDecimal.print();
    cout << endl << "Decimal Value: " << largestDecimal.getDecimal() << endl;

    return 0;
}