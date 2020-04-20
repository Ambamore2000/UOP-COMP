#ifndef CITY_H
#define CITY_H
#include<string>

#include <utility>
#include <iostream>

using namespace std;

class City {
public:
	City(string nm, unsigned int pop) {
		namePopulationPair = make_pair(nm, pop);
	}
	void setName(string name) {this -> namePopulationPair.first = name;}
	void setPopulation(unsigned int population) {this -> namePopulationPair.second = population;}
	string getName() const {return this-> namePopulationPair.first;}
	unsigned int getPopulation() const {return this -> namePopulationPair.second;}
	virtual void printInfo() const { cout<<getName()<<": "<<getPopulation()<<endl; }

	bool operator<(const City &city) const {
		return (this->getName() < city.getName());
	}
	bool operator>(const City &city) const {
		return (this->getPopulation() > city.getPopulation());
	}
protected:
	pair<string, int> namePopulationPair;
};
#endif
