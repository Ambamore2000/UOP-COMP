#ifndef CITYPRIORITYQUEUE_H
#define CITYPRIORITYQUEUE_H
#include "cityheap.h"
class CityPriorityQueue {
public:
    CityPriorityQueue(CityMaxHeap &h) { heap = h; }
    void pushCity(City city) { heap.insert(city); }
    void popCity() { heap.remove(); }
    City*peekCity() { return &heap.array[0];}
    bool isEmpty() { return heap.arraySize == 0;}
    int getLength() { return heap.arraySize; }
private:
    CityMaxHeap heap;
};
#endif