#include <iostream>
#include <windows.h>

using namespace std;

class Coordinate {
    public:
        int x;
        int y;
        int color;

        void set(int x, int y, int color);
        int getX();
        int getY();
        void move(int horizontal, int vertical);
        void rotate();
        void display();
};

void Coordinate::set(int initX, int initY, int initColor) {
    x = initX;
    y = initY;
    color = initColor;
}

int Coordinate::getX() {
    return x;
}
int Coordinate::getY() {
    return y;
}

void Coordinate::move(int horizontal, int vertical) {
    set(x + horizontal, y + vertical, color);
}

void Coordinate::rotate() {
    set(-y, x, color);
}

void Coordinate::display() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    string quadrant = "ERROR";

    if (x > 0 && y > 0)
        quadrant = "I";
    else if (x < 0 && y > 0)
        quadrant = "II";
    else if (x < 0 && y < 0)
        quadrant = "III";
    else if (x > 0 && y < 0)
        quadrant = "IV";

    if (quadrant == "ERROR")
        cout << "(" << x << ", " << y << ")" << endl;
    else
        cout << "(" << x << ", " << y << ") is in quadrant " << quadrant << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

int slope(int xOne, int xTwo, int yOne, int yTwo) {
    return (yTwo - yOne)/(xTwo - xOne);
}

int main() {

    Coordinate A, B, C;

    cout << "Rotating A:" << endl;
    A.set(1, 2, 5); //A = purple
    A.display();

    for (int x = 0; x < 4; x++) {
        A.rotate();
        A.display();
    }

    cout << "Incrementing B:" << endl;
    B.set(2, 3, 1); //B = blue
    B.display();

    B.move(1, 1);
    B.display();

    cout << "Move C to origin:" << endl;
    C.set(5, -4, 2); //C = green
    C.display();
    C.set(0, 0, 2);
    C.display();

    cout << "Slope of A to B = " << slope(A.getX(), B.getX(), A.getY(), B.getY());

    return 0;
}
