#ifndef CITYLIST_H
#define CITYLIST_H
#include<string>
#include "citynode.h"
class CityList {
public:
	CityList() {
		head = tail = nullptr;
	}
	/*
	ListAppend(list, newNode) {
		if (list⇢head == null) { // List empty
			list⇢head = newNode
			list⇢tail = newNode
		}
		else {
			list⇢tail⇢next = newNode
			newNode⇢prev = list⇢tail
			list⇢tail = newNode
		}
	}*/
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
	/*
	ListPrepend(list, newNode) {
		if (list⇢head == null) { // List empty
			list⇢head = newNode
			list⇢tail = newNode
		}
		else {
			newNode⇢next = list⇢head
			list⇢head⇢prev = newNode
			list⇢head = newNode
		}
	}*/
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
	/*
	ListTraverse(list) {
			curNode = list⇢head // Start at head

			while (curNode is not null) {
				Print curNode's data
				curNode = curNode⇢next
			}
	}*/
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
	/*
	ListInsertAfter(list, curNode, newNode) {
		if (list⇢head == null) { // List empty
			list⇢head = newNode
			list⇢tail = newNode
		}
		else if (curNode == list⇢tail) { // Insert after tail
			list⇢tail⇢next = newNode
			newNode⇢prev = list⇢tail
			list⇢tail = newNode
		}
		else {
			sucNode = curNode⇢next
			newNode⇢next = sucNode
			newNode⇢prev = curNode
			curNode⇢next = newNode
			sucNode⇢prev = newNode
		}
	}*/
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
	/*
	ListRemove(list, curNode) {
		sucNode = curNode⇢next
		predNode = curNode⇢prev

		if (sucNode is not null) {
			sucNode⇢prev = predNode
		}

		if (predNode is not null) {
			predNode⇢next = sucNode
		}

		if (curNode == list⇢head) { // Removed head
			list⇢head = sucNode
		}

		if (curNode == list⇢tail) { // Removed tail
			list⇢tail = predNode
		}
	}*/
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
private:
	CityNode *head;
	CityNode *tail;
};
#endif