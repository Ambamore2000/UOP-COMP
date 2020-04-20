#ifndef CITYLIST_H
#define CITYLIST_H
#include<string>
#include "citynode.h"
class CityList {
public:
	CityList() { head = tail = nullptr; }
	/*
	 ListAppend(list, newNode) {
   if (list⇢head == null) { // List empty
      list⇢head = newNode
      list⇢tail = newNode
   }
   else{
      list⇢tail⇢next = newNode
      list⇢tail = newNode
   }
}
	 */
	void append(CityNode *cityNode) {
		if (head == nullptr) { // List empty
			head = cityNode;
			tail = cityNode;
		}
		else{
			tail->next = cityNode;
			tail = cityNode;
		}
	}
	/*
	 ListPrepend(list, newNode) {
   if (list⇢head == null) { // list empty
      list⇢head = newNode
      list⇢tail = newNode
   }
   else {
      newNode⇢next = list⇢head
      list⇢head = newNode
   }
}
	 */
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
	/*

ListSearch(list, key) {
   curNode = list⇢head
   while (curNode is not null) {
      if (curNode⇢data == key) {
         return curNode
      }
      curNode = curNode⇢next
   }
   return null
}
	 */
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
private:
	CityNode *head;
	CityNode *tail;

};
#endif