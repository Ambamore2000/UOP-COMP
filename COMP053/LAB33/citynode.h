#ifndef CITYNODE_H
#define CITYNODE_H

#include <string>
#include "city.h"

class CityNode {
public:
    CityNode(City city) { data = city; left = nullptr; right = nullptr; }

    City data;
    CityNode *left;
    CityNode *right;
};
#endif