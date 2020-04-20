#ifndef CITYDEQUE_H
#define CITYDEQUE_H
#include "citylist.h"
class CityDeque {
public:
    CityDeque(CityList &l) { lst = l; }
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
    void pushFrontCityNode(CityNode *cityNode) { lst.prepend(cityNode); }
    void pushBackCityNode(CityNode *cityNode) { lst.append(cityNode); }
    CityNode *popFrontCityNode() {
        CityNode *poppedCity = lst.getHead();
        lst.remove(lst.getHead());
        return poppedCity;
    }
    CityNode *popBackCityNode() {
        CityNode *poppedCity = lst.getTail();
        lst.remove(lst.getTail());
        return poppedCity;
    }
    CityNode *peekFrontCityNode() { return lst.getHead(); }
    CityNode *peekBackCityNode() { return lst.getTail(); }
    bool isEmpty() { return lst.getHead() == nullptr; }
private:
    CityList lst;
};
#endif