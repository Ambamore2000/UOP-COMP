#ifndef CITYBST_H
#define CITYBST_H
#include <string>
#include "citynode.h"

class CityBST {
public:
    CityBST() { root = nullptr; }
    CityNode *root;
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
    }
    void printCityBST() { printCityBSTRecursive(root,0); }
    /*BSTRemove(tree, key) {
        par = null
        cur = tree⇢root
        while (cur is not null) { // Search for node
            if (cur⇢key == key) { // Node found 
                if (!cur⇢left && !cur⇢right) {        // Remove leaf
                    if (!par) // Node is root
                        tree⇢root = null
                    else if (par⇢left == cur)
                    par⇢left = null
                    else
                    par⇢right = null
                }
                else if (cur⇢left && !cur⇢right) {    // Remove node with only left child
                    if (!par) // Node is root
                        tree⇢root = cur⇢left
                    else if (par⇢left == cur)
                    par⇢left = cur⇢left
                    else
                    par⇢right = cur⇢left
                }
                else if (!cur⇢left && cur⇢right) {    // Remove node with only right child
                    if (!par) // Node is root
                        tree⇢root = cur⇢right
                    else if (par⇢left == cur)
                    par⇢left = cur⇢right
                    else
                    par⇢right = cur⇢right
                }
                else {                                  // Remove node with two children
                    // Find successor (leftmost child of right subtree)
                    suc = cur⇢right
                    while (suc⇢left is not null)
                    suc = suc⇢left
                    successorData = Create copy of suc's data
                    BSTRemove(tree, suc⇢key)     // Remove successor
                    Assign cur's data with successorData
                }
                return // Node found and removed
            }
            else if (cur⇢key < key) { // Search right
                par = cur
                cur = cur⇢right
            }
            else {                     // Search left
                par = cur
                cur = cur⇢left
            }
        }
        return // Node not found
    }*/
    void remove(unsigned int pop) {
        CityNode *par = nullptr;
        CityNode *cur = root;
        while (cur != nullptr) { // Search for node
            if (cur->data.getPopulation() == pop) { // Node found
                if (!cur->left && !cur->right) {        // Remove leaf
                    if (!par) // Node is root
                        root = nullptr;
                    else if (par->left == cur)
                        par->left = nullptr;
                    else
                        par->right = nullptr;
                } else if (cur->left && !cur->right) {    // Remove node with only left child
                    if (!par) // Node is root
                        root = cur->left;
                    else if (par->left == cur)
                        par->left = cur->left;
                    else
                        par->right = cur->left;
                } else if (!cur->left && cur->right) {    // Remove node with only right child
                    if (!par) // Node is root
                        root = cur->right;
                    else if (par->left == cur)
                        par->left = cur->right;
                    else
                        par->right = cur->right;
                } else {                                  // Remove node with two children
                    // Find successor (leftmost child of right subtree)
                    CityNode *suc = cur->right;
                    while (suc->left != nullptr)
                        suc = suc->left;
                    City successorData = suc->data;         // successorData = Create copy of suc's data
                    remove(suc->data.getPopulation());     // Remove successor
                    cur->data = successorData;//Assign cur's data with successorData
                }
                return; // Node found and removed
            } else if (cur->data.getPopulation() < pop) { // Search right
                par = cur;
                cur = cur->right;
            } else {                     // Search left
                par = cur;
                cur = cur->left;
            }
        }
        // Node not found
    }
    CityNode *search(unsigned int pop) { return searchRecursive(root, pop); }
    void printCityBST_InOrder() { printCityBST_InOrderRecursive(root); }
    int getHeight() { return getHeightRecursive(root); }
private:
    void printCityBSTRecursive(CityNode *cityNode, int n) {
        if (cityNode == nullptr)
            return;
        for (int x = 0; x < n; x++) { cout << "  "; }

        cityNode->data.printInfo();

        printCityBSTRecursive(cityNode->left, n+1);
        printCityBSTRecursive(cityNode->right, n+1);
    }
    /*BSTSearchRecursive(node, key) {
        if (node is not null) {
            if (key == node⇢key)
            return node
            else if (key < node⇢key) {
                return BSTSearchRecursive(node⇢left, key)
                else
                return BSTSearchRecursive(node⇢right, key)
            }
            return null
        }*/
    CityNode *searchRecursive(CityNode *cityNode, unsigned int pop) {
        if (cityNode != nullptr) {
            if (pop == cityNode->data.getPopulation()) {
                return cityNode;
            } else if (pop < cityNode->data.getPopulation()) {
                return searchRecursive(cityNode->left, pop);
            } else {
                return searchRecursive(cityNode->right, pop);
            }
        }
        return nullptr;
    }
    /*BSTPrintInorder(node) {
            if (node is null)
            return

            BSTPrintInorder(node⇢left)
            Print node
            BSTPrintInorder(node⇢right)
    }*/
    void printCityBST_InOrderRecursive(CityNode *cityNode) {
        if (cityNode == nullptr)
            return;

        printCityBST_InOrderRecursive(cityNode->left);
        cityNode->data.printInfo();
        printCityBST_InOrderRecursive(cityNode->right);
    }
    /*BSTGetHeight(node) {
            if (node is null)
            return -1

            leftHeight = BSTGetHeight(node⇢left)
            rightHeight = BSTGetHeight(node⇢right)
            return 1 + max(leftHeight, rightHeight)
    }*/
    int getHeightRecursive(CityNode *cityNode) {
        if (cityNode == nullptr)
            return -1;

        int leftHeight = getHeightRecursive(cityNode->left);
        int rightHeight = getHeightRecursive(cityNode->right);
        return 1 + max(leftHeight, rightHeight);
    }
};

#endif