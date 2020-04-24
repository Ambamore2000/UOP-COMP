#include <iostream>
#include "city.h"
#include "cityheap.h"
#include "citypriorityqueue.h"

City cityArray[] = {
        City("Sacramento",505628),
        City("Eugene",221452),
        City("Stockton",323761),
        City("Redding",90292),
        City("San Diego",1591688),
        City("Reno",289485),
        City("Los Angeles",4340174),
        City("Portland",730428),
        City("Las Vegas",711926),
        City("Seattle",752180),
        City("San Francisco",871421)
};

CityMaxHeap cityHeap = CityMaxHeap();

void readFront(CityPriorityQueue cityPQueue) {
    cout << "Reading the front of cityPQueue: ";
    cityPQueue.peekCity()->printInfo();
    cout << endl;
}

int main() {
    cout << "Initializing cityHeap with cityArray[] using appending:" << endl;
    cityHeap = CityMaxHeap(cityArray, 11);

    cityHeap.printHeap();
    cout << endl;

    CityPriorityQueue cityPQueue = CityPriorityQueue(cityHeap);

    cout << "Is cityPQueue empty? " <<  cityPQueue.isEmpty() << endl;
    cout << "Length of cityPQueue: " << cityPQueue.getLength() << endl;
    cout << endl;

    readFront(cityPQueue);

    cout << "Removing the item at the front of cityPQueue." << endl;
    cityPQueue.popCity();
    readFront(cityPQueue);

    cout << "Inserting Phoenix with population 1660472 into CityPQueue." << endl;
    cityPQueue.pushCity(City("Phoenix", 1660472));
    cout << "Inserting Santa Fe with population 84263 into CityPQueue." << endl;
    cityPQueue.pushCity(City("Santa Fe", 84263));
    readFront(cityPQueue);

    cout << "Length of cityPQueue: " << cityPQueue.getLength() << endl;

    return 0;
}
