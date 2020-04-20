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
		if (head == nullptr) { // List empty
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
		if (head == nullptr) { // List empty
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
		CityNode *curNode = head;
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
		if (head == nullptr) { // List empty
			head = cityNode;
			tail = cityNode;
		}
		else if (currNode == tail) { // Insert after tail
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

	/*
	ListInsertionSortDoublyLinked(list) {
		curNode = list⇢head⇢next
		while (curNode != null) {
			nextNode = curNode⇢next
			searchNode = curNode⇢prev
			while (searchNode != null and searchNode⇢data > curNode⇢data)
			searchNode = searchNode⇢prev

			// Remove and re-insert curNode
			ListRemove(list, curNode)
			if (searchNode == null) {
				curNode⇢prev = null
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