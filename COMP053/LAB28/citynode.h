#ifndef CITYNODE_H
#define CITYNODE_H
#include<string>
#include "city.h"

class CityNode {
public:
	City data;
	CityNode *next;
	CityNode *prev;
	CityNode(City city) { data = city; next = nullptr; prev = nullptr; }
};

#endif