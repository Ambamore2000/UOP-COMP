#ifndef CITYBST_H
#define CITYBST_H

#include<string>
#include "citynode.h"

class CityBST {
public:
    CityNode *root;
    CityBST() {
        root = nullptr;
    }
    /*Complete the definition of void insert(...) function that receives a pointer to a CityNode,
    and adds that node to the BST. You need to insert the node into the tree according to the city’s
    population (5 points).

    BSTInsert(tree, node) {
        if (root is null)
        root = node
        node⇢left = null
        node⇢right = null
        else
        cur = root
        while (cur is not null)
        if (node⇢key < cur⇢key)
        if (cur⇢left is null)
        cur⇢left = node
        cur = null
        else
        cur = cur⇢left
        else
        if (cur⇢right is null)
        cur⇢right = node
        cur = null
        else
        cur = cur⇢right
        node⇢left = null
        node⇢right = null
    }*/

    /*
    void insert(CityNode *cityNode) {
        if (root == nullptr) {
            root = cityNode;
            cityNode->left = nullptr;
            cityNode->right = nullptr;
        } else {
            CityNode *cur = root;
            while (cur != nullptr) {
                if (cityNode->data.getPopulation() < cur->data.getPopulation()) {
                    if (cur->left == nullptr) {
                        cur->left = cityNode;
                        cur = nullptr;
                    } else {
                        cur = cur->left;
                    }
                } else {
                    if (cur->right == nullptr) {
                        cur->right = cityNode;
                        cur = nullptr;
                    } else {
                        cur = cur->right;
                    }
                }
            }
            cityNode->left = nullptr;
            cityNode->right = nullptr;
        }
    }*/
    void insert(CityNode *cityNode) {
        CityNode *cur = nullptr;

        cityNode->left = nullptr;
        cityNode->right = nullptr;
        if (root == nullptr) {
            root = cityNode;
        } else {
            cur = root;
        }
        while (cur != nullptr) {
            if (cityNode->data.getPopulation() < cur->data.getPopulation()) {
                if (cur->left == nullptr) {
                    cur->left = cityNode;
                    cur = nullptr;
                } else {
                    cur = cur->left;
                }
            } else if (cur->right == nullptr) {
                cur->right = cityNode;
                cur = nullptr;
            } else {
                cur = cur->right;
            }
        }
        //cityNode->left = nullptr;
        //cityNode->right = nullptr;

    }

    /*Complete the definition of CityNode *search(...) function that receives a city population
    (an unsigned integer). It traverses the BST to find the city with that population, and returns a pointer
    to that node if successful. Otherwise, it returns null pointer (5 points).
    cur = tree⇢root
    while (cur is not null)
    if (key == cur⇢key)
    return cur // Found
    else if (key < cur⇢key)
    cur = cur⇢left
    else
    cur = cur⇢right
    return null // Not found*/
    CityNode *search(unsigned int pop, CityNode *cur) {
        cur = root;
        while (cur != nullptr) {
            if (pop == cur->data.getPopulation())
                return cur; // Found
            else if (pop < cur->data.getPopulation())
                cur = cur->left;
            else
                cur = cur->right;
        }
        return nullptr;
    }
    void printCityBST() {
        printCityBSTRecursive(root,0);
    }
private:
    /*(a) Check if the input cityNode is null. If so, return. (There is nothing to print!)
    (b) Print white space for n times.
    (c) Print the information of the city pointed by cityNode. (Call printInfo()!)
    (d) Recursively call the function on the left subtree of cityNode with indentation number n+1.
    (e) Recursively call the function on the right subtree of cityNode with indentation number n+1.*/
    void printCityBSTRecursive(CityNode *cityNode, int n) {
        if (cityNode == nullptr)
            return;
        for (int x = 0; x < n; x++) { cout << "  "; }

        cityNode->data.printInfo();

        printCityBSTRecursive(cityNode->left, n+1);
        printCityBSTRecursive(cityNode->right, n+1);

    }
};
#endif
