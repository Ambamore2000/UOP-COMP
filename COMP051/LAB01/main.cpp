// Lab 1 - Andrew Kim

#include <iostream>
#include <string>

using namespace std;

int main() {

	/*
		First part.
	*/

	cout << " - MadLibsForLab1 01 - " << endl
		<< "Hello... What's your name?" << endl;

	string name;
	cin >> name;

	cout << "So... " << name << " ..." << endl;

	cout << "wHaT iS yOuR lUcKy NuMbEr? (number)" << endl;
	string favoriteNumber;
	cin >> favoriteNumber;

	cout << "WhAt Is YoUr FaVoRiTe FoOd? (noun)" << endl;
	string favoriteFood;
	cin >> favoriteFood;

	cout << "tElL mE sOmEtHiNg yOu DiD yEsTeRdAy! (verb)" << endl;
	string someVerb;
	cin >> someVerb;

	cout << "Sucks for you, " << name  << ". "
		<< "I'm going to " << someVerb 
		<< " your " << favoriteFood 
		<< " " << favoriteNumber 
		<< " times." << endl;

	/*
		Second part.
	*/

	cout << "WhAt Is YoUr FaVoRiTe FlOwEr? (noun)" << endl;
	string favoriteFlowerOne;
	cin >> favoriteFlowerOne;

	cout << "WhAt Is YoUr SeCoNd FaVoRiTe FlOwEr? (noun)" << endl;
	string favoriteFlowerTwo;
	cin >> favoriteFlowerTwo;


	cout << "WhAt Is YoUr FaVoRiTe CaNdY? (noun)" << endl;
	string favoriteCandy;
	cin >> favoriteCandy;

	cout << "HoW wOuLd YoU dEsCriBe YoUrSeLf? (adjective)" << endl;
	string selfAdjective;
	cin >> selfAdjective;

	cout << favoriteFlowerOne << " are red, " << endl
		<< favoriteFlowerTwo << " are blue," << endl
		<< favoriteCandy << " is " << selfAdjective << "," << endl
		<< "But not you " << name << ". (:" << endl;
	
	/*
		Third part.
	*/

	cout << "NaMe Me A sHaPe!" << endl;
	string shape;
	cin >> shape;

	cout << "In the " << shape << " of life..." << endl
		<< "It's the wheel of fortune..." << endl
		<< "It's the " << someVerb << " of faith..." << endl
		<< "It's the band of hope..." << endl
		<< "'Til we find our place..." << endl
		<< "On the path unwinding..." << endl
		<< "In the " << shape << ", the " << shape << " of life..." << endl;

	cout << "Credits: Circle of Life by Elton John.";

	system("pause");

	return 0;
}