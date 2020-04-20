#ifndef CITYSTACK_H
#define CITYSTACK_H
#include "citylist.h"
class CityStack {

public:
    CityStack(CityList &l) { lst = l; }
    /*StackPush(stack, newItem) {
        ListPrepend(stack, newItem)  // Insert as list head (top of stack)
    }

    StackPop(stack) {
            poppedItem = stack⇢head     // Copy list head (top of stack)
            ListRemoveAfter(stack, null) // Remove list head
            return poppedItem            // Return popped item
    }*/
    void pushCityNode(CityNode *cityNode) { lst.prepend(cityNode); }
    CityNode *popCityNode() {
        if (isEmpty()) return nullptr;
        CityNode *poppedItem = lst.getHead();
        lst.remove(poppedItem);
        return poppedItem;
    }
    CityNode *peekCityNode() {
        if (isEmpty()) return nullptr;
        return lst.getHead();
    }
    bool isEmpty() { return (lst.getHead() == nullptr); }

private:
    CityList lst;
};
#endif
