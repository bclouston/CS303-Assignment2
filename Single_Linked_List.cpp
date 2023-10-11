//
//  Single_Linked_List.cpp
//  CS303A2
//
//  Created by Brendan Clouston on 10/3/23.
//

#include "Single_Linked_List.h"

Single_Linked_List::Single_Linked_List() {
    headPtr = nullptr;
    tailPtr = nullptr;
    num_items = 0;
}

Single_Linked_List::Single_Linked_List(const Item_Type& item) {
    Node* newNode = new Node;
    newNode->data = item;
    newNode->nextPtr = nullptr;
    headPtr = newNode;
    tailPtr = newNode;
    num_items = 1;
}

void Single_Linked_List::push_front(const Item_Type& item) {
    Node* newNode = new Node;
    newNode->data = item;
    newNode->nextPtr = headPtr;
    headPtr = newNode;
    //check if list was empty and initialize tailPtr
    if (tailPtr == nullptr) {
        tailPtr = newNode;
    }
    num_items++;
}

void Single_Linked_List::push_back(const Item_Type& item) {
    Node* newNode = new Node;
    newNode->data = item;
    newNode->nextPtr = nullptr;
    tailPtr->nextPtr = newNode;
    tailPtr = newNode;
    //check if list was empty and initialize headPtr
    if (headPtr == nullptr) {
        headPtr = newNode;
    }
    num_items++;
}

void Single_Linked_List::pop_front() {
    if (headPtr == nullptr) {
        cout << "Can not delete from an empty list" << endl;
        return;
    }
    Node* delNode = headPtr;
    headPtr = headPtr->nextPtr;
    delete delNode;
    num_items--;
}

void Single_Linked_List::pop_back() {
    if (headPtr == nullptr) {
        cout << "Can not delete from an empty list" << endl;
        return;
    }
    Node* tempNode = headPtr;
    while (tempNode != nullptr && tempNode->nextPtr != tailPtr) {
        tempNode = tempNode->nextPtr;
    }
    tailPtr = tempNode;
    tempNode = tempNode->nextPtr;
    tailPtr->nextPtr = nullptr;
    delete tempNode;
    num_items--;
}

Node* Single_Linked_List::front() {
    if (headPtr == nullptr) {
        cout << "Can not return element from an empty list" << endl;
        return nullptr;
    }
    else {
        return headPtr;
    }
}

Node* Single_Linked_List::back() {
    if (headPtr == nullptr) {
        cout << "Can not return element from an empty list" << endl;
        return nullptr;
    }
    else { return tailPtr; }
}

bool Single_Linked_List::empty() const {
    if (headPtr == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

void Single_Linked_List::insert(size_t index, const Item_Type &item) {
    int counter = 0;
    Node* newNode = new Node;
    newNode->data = item;
    Node* tempNode = headPtr;
    //insert as only item if list is empty
    if (tempNode == nullptr) {
        push_front(item);
        return;
    }
    while (counter != (index - 1)) {
        tempNode = tempNode->nextPtr;
        counter++;
        //check if index is out of bounds and add item to end of list
        if (tempNode == nullptr) {
            push_back(item);
            return;
        }
    }
    newNode->nextPtr = tempNode->nextPtr;
    tempNode->nextPtr = newNode;
    num_items++;
}

bool Single_Linked_List::remove(size_t index) {
    int counter = 0;
    Node* tempNode = headPtr;
    while (counter < (index - 1)) {
        tempNode = tempNode->nextPtr;
        counter++;
        if (tempNode == nullptr) {
            return false;
        }
    }
    Node* delNode = tempNode->nextPtr;
    tempNode->nextPtr = delNode->nextPtr;
    delete delNode;
    num_items--;
    return true;
}

size_t Single_Linked_List::find(const Item_Type &item) {
    size_t index = 0;
    Item_Type tempItem = item;
    Node* tempNode = headPtr;
    while (index < num_items) {
        if (tempItem.testValue == tempNode->data.testValue) {
            return index;
        }
        tempNode = tempNode->nextPtr;
        index++;
    }
    return index;
}

void Single_Linked_List::printList() {
    Node* tempPtr = headPtr;
    while (tempPtr != nullptr) {
        cout << tempPtr->data.testValue << " ";
        tempPtr = tempPtr->nextPtr;
    }
}
