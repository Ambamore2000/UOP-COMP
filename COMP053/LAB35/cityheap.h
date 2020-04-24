#ifndef CITYHEAP_H
#define CITYHEAP_H

#include <string>
#include "city.h"

const int maxArraySize = 100;
class CityMaxHeap {
public:
    City array[maxArraySize];
    int arraySize;
    CityMaxHeap() {
        arraySize = 0;
    }
    CityMaxHeap(City arr[], int size) {
        for(int i = 0; i < size; i++)
            array[i] = arr[i];
        arraySize = size;
        cityHeapify();
    }
    void printHeap() { cityHeapify(); for (int i = 0; i < arraySize; i++) array[i].printInfo(); }
    /*Define function void insert(...) that receives a city as input and adds it to the max heap.
    Hint: Use percolateUp(...) function. Moreover, do not forget to update the array size (3
    points).*/
    //Used http://www.algolist.net/Data_structures/Binary_heap/Insertion
    void insert(City city) {
        arraySize++;

        array[arraySize - 1] = city;

        percolateUp(arraySize - 1);
        /*
        int index = arraySize;
        percolateUp(index);
        array[index] = city;
        arraySize++;*/
        //cityHeapify();
    }
    /*Define function void remove() that removes the root of the max heap and then adjusts it to
    satisfy being a max heap. Hint: Use percolateDown(...) function. Moreover, do not forget
            to update the array size (3 points).*/
    //Used http://www.algolist.net/Data_structures/Binary_heap/Remove_minimum
    void remove() {
        array[0] = array[arraySize - 1];

        arraySize--;

        if (arraySize > 0)
            percolateDown(0, arraySize);
    }
    /*Heapsort(numbers, numbersSize) {
        // Heapify numbers array
        for (i = numbersSize / 2 - 1; i >= 0; i--)
            MaxHeapPercolateDown(i, numbers, numbersSize)

        for (i = numbersSize - 1; i > 0; i--) {
            swap numbers[0] and numbers[i]
            MaxHeapPercolateDown(0, numbers, i)
        }
    }*/
    void heapSort() {
        for (int i = arraySize / 2 - 1; i >= 0; i--)
            percolateDown(i, arraySize);

        for (int i = arraySize - 1; i > 0; i--) {
            //swap numbers[0] and numbers[i]
            City temp = array[0];
            array[0] = array[i];
            array[i] = temp;
            percolateDown(0, i);
        }
    }
private:
    /*MaxHeapPercolateUp(nodeIndex, heapArray) {
        while (nodeIndex > 0) {
            parentIndex = (nodeIndex - 1) / 2
            if (heapArray[nodeIndex] <= heapArray[parentIndex])
                return
            else {
                swap heapArray[nodeIndex] and heapArray[parentIndex]
                nodeIndex = parentIndex
            }
        }
    }*/
    void percolateUp(int nodeInd) {
        while (nodeInd > 0) {
            int parentIndex = (nodeInd - 1) / 2;;
            if (array[nodeInd].getPopulation() <= array[parentIndex].getPopulation()) {
                return;
            } else {
                //swap heapArray[nodeIndex] and heapArray[parentIndex]
                City temp = array[nodeInd];
                array[nodeInd] = array[parentIndex];
                array[parentIndex] = temp;
                nodeInd = parentIndex;
            }
        }
    }
    /*MaxHeapPercolateDown(nodeIndex, heapArray, arraySize) {
        childIndex = 2 * nodeIndex + 1
        value = heapArray[nodeIndex]

        while (childIndex < arraySize) {
            // Find the max among the node and all the node's children
            maxValue = value
            maxIndex = -1
            for (i = 0; i < 2 && i + childIndex < arraySize; i++) {
                if (heapArray[i + childIndex] > maxValue) {
                    maxValue = heapArray[i + childIndex]
                    maxIndex = i + childIndex
                }
            }

            if (maxValue == value) {
                return
            }
            else {
                swap heapArray[nodeIndex] and heapArray[maxIndex]
                nodeIndex = maxIndex
                childIndex = 2 * nodeIndex + 1
            }
        }
    }*/
    void percolateDown(int nodeIndex, int size) {
        int childIndex = 2 * nodeIndex + 1;
        int value = array[nodeIndex].getPopulation();

        while (childIndex < size) {
            // Find the max among the node and all the node's children
            int maxValue = value;
            int maxIndex = -1;
            for (int i = 0; i < 2 && i + childIndex < size; i++) {
                if (array[i + childIndex].getPopulation() > maxValue) {
                    maxValue = array[i + childIndex].getPopulation();
                    maxIndex = i + childIndex;
                }
            }

            if (maxValue == value) {
                return;
            }
            else {
                //swap heapArray[nodeIndex] and heapArray[maxIndex]
                City temp = array[nodeIndex];
                array[nodeIndex] = array[maxIndex];
                array[maxIndex] = temp;
                nodeIndex = maxIndex;
                childIndex = 2 * nodeIndex + 1;
            }
        }
    }

    void cityHeapify() { for(int i = 0; i < arraySize; i++) percolateDown(i, arraySize); }
};
#endif