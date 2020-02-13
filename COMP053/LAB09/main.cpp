#include <iostream>

#include <vector>
using namespace std;

const int SIZE = 10;

int a[] = {5, 7,-2, 8, 11, -9, 4, 6, 12,-1};
int b[] = {4,16,9,-2, 1, 1, -2, 9, 16,4};
vector<int> vec1, vec2, vec3;

void initVector(vector<int> &vec, int arr[], int numberOfElements) {
    vec.resize(numberOfElements);
    for (int i = 0; i < vec.size(); i++) {
        vec.at(i) = arr[i];
    }
}

void printVector(const vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i);
        if (i != vec.size() - 1)
            cout << ", ";
    }
    cout << endl;
}

int minVector(const vector<int> vec) {
    int minVal = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec.at(i) < minVal || i == 0)
            minVal = vec.at(i);
    }
    return minVal;
}

int productVector(const vector<int> vec) {
    int prodVal = 1;
    for (int i = 0; i < vec.size(); i++) {
        prodVal = prodVal * vec.at(i);
    }
    return prodVal;
}

void copyVector(vector<int> &vecNewCopy, const vector<int> vecToCopy) {
    vecNewCopy = vecToCopy;
}

void greaterVector(vector<int> &vecNewCopy, const vector<int> vecCompOne, const vector<int> vecCompTwo) {
    if (vecCompOne.size() != vecCompTwo.size())
        return;
    int iterator = vecCompOne.size();
    for (int i = 0; i < iterator; i++) {
        if (vecCompOne.at(i) > vecCompTwo.at(i))
            vecNewCopy.at(i) = vecCompOne.at(i);
        else
            vecNewCopy.at(i) = vecCompTwo.at(i);
    }
}

bool isPalindrome(const vector<int> vec) {
    for (int i = 0; i < vec.size() / 2; i++) {
        if (vec.at(0 + i) != vec.at(vec.size() - 1 - i))
            return false;
    }
    return true;
}

void updateLast(vector<int> &vec, int lastItem) {
    vec.pop_back();
    vec.push_back(lastItem);
}

int main() {

    cout << "initial size of vec1: " << vec1.size() << endl;

    initVector(vec1, a, SIZE);

    cout << "size of vec1 after initialization: " << vec1.size() << endl;

    cout << "vec1 content: ";
    printVector(vec1);

    initVector(vec2, b, SIZE);

    cout << "vec2 content: ";
    printVector(vec2);

    cout << "minimum of vec1: " << minVector(vec1) << endl;
    cout << "product of vec1: " << productVector(vec1) << endl;

    copyVector(vec3, vec1);

    cout << "copy vec1 to vec3: ";
    printVector(vec3);

    greaterVector(vec3, vec2, vec1);

    cout << "collect larger elements from vec1 and vec2 to vec3: ";
    printVector(vec3);

    bool isVec1Palindrome = isPalindrome(vec1);
    bool isVec2Palindrome = isPalindrome(vec2);

    if (isVec1Palindrome)
        cout << "vec1 is Palindrome" << endl;
    else
        cout << "vec1 is not Palindrome" << endl;

    if (isVec2Palindrome)
        cout << "vec2 is Palindrome" << endl;
    else
        cout << "vec2 is not Palindrome" << endl;

    updateLast(vec3, 7);
    cout << "Updating the last element of vec3: ";
    printVector(vec3);

    return 0;
}