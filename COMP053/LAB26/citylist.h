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
		else{
			tail->next = cityNode;
			tail = cityNode;
		}
	}
	void prepend(CityNode *cityNode) {
		if (head == nullptr) { // list empty
			head = cityNode;
			tail = cityNode;
		}
		else {
			cityNode->next = head;
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
		CityNode *curNode = head;
		while (curNode != nullptr) {
			if (curNode->data.getName() == cityName) {
				return curNode;
			}
			curNode = curNode->next;
		}
		return nullptr;
	}
	/*
	ListInsertAfter(list, curNode, newNode) {
		if (list⇢head == null) { // List empty
			list⇢head = newNode
			list⇢tail = newNode
		}
		else if (curNode == list⇢tail) { // Insert after tail
			list⇢tail⇢next = newNode
			list⇢tail = newNode
		}
		else {
			newNode⇢next = curNode⇢next
			curNode⇢next = newNode
		}
	}
	*/
	void insert(CityNode *currNode, CityNode *cityNode) {
		if (head == nullptr) { // List empty
			head = cityNode;
			tail = cityNode;
		}
		else if (currNode == tail) { // Insert after tail
			tail->next = cityNode;
			tail = cityNode;
		}
		else {
			cityNode->next = currNode->next;
			currNode->next = cityNode;
		}
	}
	/*
	ListRemoveAfter(list, curNode) {
		// Special case, remove head
		if (curNode is null && list⇢head is not null) {
			sucNode = list⇢head⇢next
			list⇢head = sucNode

			if (sucNode is null) { // Removed last item
				list⇢tail = null
			}
		}
		else if (curNode⇢next is not null) {
			sucNode = curNode⇢next⇢next
			curNode⇢next = sucNode

			if (sucNode is null) { // Removed tail
				list⇢tail = curNode
			}
		}
	}
	*/
	void remove(CityNode *currNode) {
		CityNode *sucNode;
		if (currNode == nullptr && head != nullptr) {
			sucNode = head->next;
			head = sucNode;

			if (sucNode == nullptr) { // Removed last item
				tail = nullptr;
			}
		}
		else if (currNode->next != nullptr) {
			sucNode = currNode->next->next;
			currNode->next = sucNode;

			if (sucNode == nullptr) { // Removed tail
				tail = currNode;
			}
		}
	}
private:
	CityNode *head;
	CityNode *tail;
};
#endif