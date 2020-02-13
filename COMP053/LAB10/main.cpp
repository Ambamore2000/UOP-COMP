#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

char title1[30] = "Data Structures In C++";
char title2[30] = "Data   Structures		 In C++";

char password[4][30] = {"monkey", "MonnkeeY", "M8nnkeeY", "M8nnkeeY!"};

void splittedPrint(char toSplit[]) {
	for (int x = 0; toSplit[x] != '\0' || toSplit[x+1] != '\0'; ++x) {
		if (isspace(toSplit[x]) && !isspace(toSplit[x+1])) {
			cout << endl;
			continue;
		}
		cout << (char) toSplit[x];
	}
	cout << endl;
}

void stringFlipCase(char toFlip[]) {
	for (int x = 0; toFlip[x] != '\0'; ++x) {
		if (isupper(toFlip[x])) {
			cout << (char) tolower(toFlip[x]);
		} else if (islower(toFlip[x])) {
			cout << (char) toupper(toFlip[x]);
		} else {
			cout << toFlip[x];
		}
	}
	cout << endl;
}

void stringTrimNonAlphanumeric(char toTrim[]) {
	for (int x = 0; toTrim[x] != '\0'; ++x) {
		if (isalnum(toTrim[x])) {
			cout << toTrim[x];
		}
		//cout << endl << "X: " << x << endl;
	}
	cout << endl;
}

bool isValidPassword(char pass[]) {
	bool validPass = true;

	if (strlen(pass) <= 7) {
		cout << pass << " Not Accepted: Passwords must be at least 8 characters long." << endl;
		validPass = false;
	}
	bool hasOneLowerAlpha = false,
			hasOneUpperAlpha = false,
			hasOneDigit = false,
			hasOneSpecialCharacter = false;

	for (int x = 0; pass[x] != '\0'; ++x) {
		if (isalpha(pass[x])) {
			if (isupper(pass[x]))
				hasOneUpperAlpha = true;
			if (islower(pass[x]))
				hasOneLowerAlpha = true;
		}
		if (isdigit(pass[x]))
			hasOneDigit = true;
		if (ispunct(pass[x]))
			hasOneSpecialCharacter = true;
	}

	if (!hasOneLowerAlpha) {
		cout << pass << " Not Accepted: Passwords must at least indluce one lowercase alphabetic character." << endl;
		validPass = false;
	}
	if (!hasOneUpperAlpha) {
		cout << pass << " Not Accepted: Passwords must at least indluce one uppercase alphabetic character." << endl;
		validPass = false;
	}
	if (!hasOneDigit) {
		cout << pass << " Not Accepted: Passwords must at least indluce one digit." << endl;
		validPass = false;
	}
	if (!hasOneSpecialCharacter) {
		cout << pass << " Not Accepted: Passwords must at least indluce one special character: !\"#$%&’()*+,-./:;<=>?@[\\]^_‘{|}~" << endl;
		validPass = false;
	}
	if (validPass)
		cout << pass << " Accepted." << endl;

	return validPass;
}

int main() {

	cout << "Splitting title1:" << endl;
	splittedPrint(title1);
	cout << endl;

	cout << "Splitting title2:" << endl;
	splittedPrint(title2);
	cout << endl;

	cout << "Flipping the case in title1: ";
	stringFlipCase(title1);

	cout << "Trimming non-alphanumeric characters in title1: ";
	stringTrimNonAlphanumeric(title1);

	cout << "Trimming non-alphanumeric characters in title2: ";
	stringTrimNonAlphanumeric(title2);

	cout << endl;
	for (int i = 0; i < 4; i++) {
		isValidPassword(password[i]);
		cout << endl;
	}

	return 0;
}