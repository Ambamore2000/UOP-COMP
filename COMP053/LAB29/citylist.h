#ifndef CITYLIST_H
#define CITYLIST_H
#include<string>
#include "citynode.h"
class CityList {
public:
	CityList() {
		head = tail = new CityNode(City());
	}
	/*
	ListAppend(list, cityNode) {
		list->tail->next = cityNode
		cityNode->prev = list->tail
		list->tail = cityNode
	}


	ListPrepend(list, cityNode) {
		firstNode = list->head->next

		// Set the next and prev pointers for cityNode
		cityNode->next = list->head->next
		cityNode->prev = list->head

		// Set the dummy node's next pointer
		list->head->next = cityNode

		// Set prev on former first node
		if (firstNode is not null) {
			firstNode->prev = cityNode
		}
	}


	ListInsertAfter(list, curNode, cityNode) {
		if (curNode == list->tail) { // Insert after tail
			list->tail->next = cityNode
			cityNode->prev = list->tail
			list->tail = cityNode
		}
		else {
			sucNode = curNode->next
			cityNode->next = sucNode
			cityNode->prev = curNode
			curNode->next = cityNode
			sucNode->prev = cityNode
		}
	}


	ListRemove(list, curNode) {
		if (curNode == list->head) {
			// Dummy node cannot be removed
			return
		}

		sucNode = curNode->next
		predNode = curNode->prev

		if (sucNode is not null) {
			sucNode->prev = predNode
		}

		// Predecessor node is always non-null
		predNode->next = sucNode

		if (curNode == list->tail) { // Removed tail
			list->tail = predNode
		}
	}
	*/
	void append(CityNode *cityNode) {
		tail->next = cityNode;
		cityNode->prev = tail;
		tail = cityNode;
	}
	void prepend(CityNode *cityNode) {
		CityNode *firstNode = head->next;

		// Set the next and prev pointers for cityNode
		cityNode->next = head->next;
		cityNode->prev = head;

		// Set the dummy node's next pointer
		head->next = cityNode;

		// Set prev on former first node
		if (firstNode != nullptr) {
			firstNode->prev = cityNode;
		}
	}
	void printCityList() {
		CityNode *curNode = head->next;
		while (curNode != nullptr) {
			curNode->data.printInfo();
			curNode = curNode->next;
		}
		cout << endl;
	}
	CityNode *search(string cityName) {
		CityNode *curNode = head; // Start at head

		while (curNode != nullptr) {
			if (curNode->data.getName() == cityName)
				return curNode;
			curNode = curNode->next;
		}
		return nullptr;
	}
	void insert(CityNode *currNode, CityNode *cityNode) {
		if (currNode == tail) { // Insert after tail
			tail->next = cityNode;
			cityNode->prev = tail;
			tail = cityNode;
		}
		else {
			CityNode *sucNode = currNode->next;
			cityNode->next = sucNode;
			cityNode->prev = currNode;
			currNode->next = cityNode;
			sucNode->prev = cityNode;
		}
	}
	void remove(CityNode *currNode) {
		if (currNode == head) {
			// Dummy node cannot be removed
			return;
		}

		CityNode *sucNode = currNode->next;
		CityNode *predNode = currNode->prev;

		if (sucNode != nullptr) {
			sucNode->prev = predNode;
		}

		// Predecessor node is always non-null
		predNode->next = sucNode;

		if (currNode == tail) { // Removed tail
			tail = predNode;
		}
	}

	/*
	ListInsertionSortDoublyLinked(list) {
		curNode = list->head->next
		while (curNode != null) {
			nextNode = curNode->next
			searchNode = curNode->prev
			while (searchNode != null and searchNode->data > curNode->data)
			searchNode = searchNode->prev

			// Remove and re-insert curNode
			ListRemove(list, curNode)
			if (searchNode == null) {
				curNode->prev = null
				ListPrepend(list, curNode)
			}
			else
				ListInsertAfter(list, searchNode, curNode)

			// Advance to next node
			curNode = nextNode
		}
	}*/

	void insertionSortByPopulation() {
		CityNode *currNode = head->next;
		while (currNode != nullptr) {
			CityNode *nextNode = currNode->next;
			CityNode *searchNode = currNode->prev;
			while (searchNode != nullptr && searchNode->data.getPopulation() > currNode->data.getPopulation())
				searchNode = searchNode->prev;

			// Remove and re-insert curNode
			remove(currNode);
			if (searchNode == nullptr) {
				currNode->prev = nullptr;
				prepend(currNode);
			}
			else
				insert(searchNode, currNode);

			// Advance to next node
			currNode = nextNode;
		}
	}


private:
	CityNode *head;
	CityNode *tail;
};
#endif