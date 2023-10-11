//
//  Single_Linked_List.h
//  CS303A2
//
//  Created by Brendan Clouston on 10/3/23.
//
#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;

struct Item_Type {
    int testValue;
};

struct Node {
    Item_Type data;
    Node* nextPtr;
};

class Single_Linked_List {
private:
    Node* headPtr;
    Node* tailPtr;
    int num_items;
    
public:
    //default constructor, creates empty list
    Single_Linked_List();
    
    //overloaded constructor, creates list and element from item passed
    Single_Linked_List(const Item_Type& item);
    
    //add item to beginning of list
    //PRE: accepts Item_Type object
    //POST: creates new list node and inserts at front of list
    void push_front(const Item_Type& item);
    
    //add item to end of list
    //PRE: accepts Item_Type object
    //POST: creates new list node and inserts at end of list
    void push_back(const Item_Type& item);
    
    //removes first item (index 0) from the list
    //PRE: list has at least one element
    //POST: deletes the node at front of the list, updates pointers
    void pop_front();
    
    //removes item from end of list
    //PRE: list has at least one element
    //POST: deletes the node at end of the list, updates pointers
    void pop_back();
    
    //returns a reference to the first element in list
    //PRE: list has at least one element
    //POST: returns node object of first element in list
    Node* front();
    
    //returns a reference to the last element in list
    //PRE: list has at least one element
    //POST: returns node object of last element in list
    Node* back();
    
    //returns a boolean response whether list is empty
    //PRE: list has been constructed
    //POST: returns true if list is empty, false otherwise
    bool empty() const;
    
    //inserts element into list at given position
    //PRE: list has been constructed, item passed
    //POST: inserts item at given index position, if out of bounds, add to end
    void insert(size_t index, const Item_Type& item);
    
    //removes item at given index
    //PRE: list has been constructed
    //POST: returns true if item has been removed successfully, false if index out of bounds
    bool remove(size_t index);
    
    //search list for item, return index position if found
    //PRE: list has at least one element
    //POST: returns index position at first occurance, list size if not found
    size_t find(const Item_Type& item);
    
    //list print function for testing purposes
    void printList();
};
