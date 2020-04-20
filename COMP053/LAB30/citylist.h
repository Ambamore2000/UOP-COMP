#ifndef CITYLIST_H
#define CITYLIST_H
#include<string>
#include "citynode.h"
class CityList {
public:

	CityList() {
		head = tail = nullptr;
	}

	void append(CityNode *cityNode) {
		if (head == nullptr) {
			head = cityNode;
			tail = cityNode;
		}
		else {
			tail->next = cityNode;
			cityNode->prev = tail;
			tail = cityNode;
		}
	}

	void prepend(CityNode *cityNode) {
		if (head == nullptr) {
			head = cityNode;
			tail = cityNode;
		}
		else {
			cityNode->next = head;
			head->prev = cityNode;
			head = cityNode;
		}
	}

	void printCityList() {
        printCityListRecursive(head);
	}

	CityNode *search(string cityName) {
        return searchRecursive(head, cityName);
    }

	void remove(CityNode *currNode) {
		CityNode *sucNode = currNode->next;
		CityNode *predNode = currNode->prev;

		if (sucNode != nullptr) {
			sucNode->prev = predNode;
		}

		if (predNode != nullptr) {
			predNode->next = sucNode;
		}

		if (currNode == head) { // Removed head
			head = sucNode;
		}

		if (currNode == tail) { // Removed tail
			tail = predNode;
		}
	}
    CityNode *getHead() { return head; }

private:
	CityNode *head;
	CityNode *tail;
    /*ListTraverseRecursive(node) {
        if (node is not null) {
            Visit node
            ListTraverseRecursive(node⇢next)
        }
    }*/
    void printCityListRecursive(CityNode *cityNode) {
        if (cityNode != nullptr) {
            cityNode->data.printInfo();
            printCityListRecursive(cityNode->next);
        }
    }
    /*ListSearchRecursive(key, node) {
        if (node is not null) {
            if (node⇢data == key) {
                return node
            }
            return ListSearchRecursive(key, node⇢next)
        }
        return null
    }*/
    CityNode *searchRecursive(CityNode *cityNode, string cityName) {
        if (cityNode != nullptr) {
            if (cityNode->data.getName() == cityName) { return cityNode; }
            return searchRecursive(cityNode->next, cityName);
        }
        return nullptr;
    }
};
#endif