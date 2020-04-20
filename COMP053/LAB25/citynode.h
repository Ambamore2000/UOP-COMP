#ifndef CITYNODE_H
#define CITYNODE_H
#include<string>
#include "city.h"

class CityNode {
public:
	City data;
	CityNode *next;
	CityNode(City city) { data = city; next = nullptr; }
};

#endif