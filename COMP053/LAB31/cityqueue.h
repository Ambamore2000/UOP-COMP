#ifndef CITYQUEUE_H
#define CITYQUEUE_H
#include "citylist.h"
class CityQueue {
public:
    CityQueue(CityList &l) { lst = l; }
    /*
    QueuePush(queue, newItem) {
        ListAppend(queue, newItem) // Insert as list tail (end of queue)
    }

    QueuePop(queue) {
            poppedItem = queue⇢head      // Copy list head (front of queue)
            ListRemoveAfter(queue, null) // Remove list head
            return poppedItem            // Return popped item
    }
    */
    void pushCityNode(CityNode *cityNode) { lst.append(cityNode); }
    CityNode *popCityNode() {
        CityNode *poppedCity = lst.getHead();
        lst.remove(lst.getHead());
        return poppedCity;
    }
    CityNode *peekCityNode() { return lst.getHead(); }
    bool isEmpty() { return lst.getHead() == nullptr; }
private:
    CityList lst;
};
#endif
