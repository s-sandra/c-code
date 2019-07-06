/*
@author Sandra Shtabnaya

assignment: name surfer
purpose: defines linked list, to contain NameSurferEntries
*/

#ifndef LIST_CPP
#define LIST_CPP
#include "linked_list.h"
#include <iostream>
#include <string>
using namespace std;

// constructor
template <class NODETYPE>
linked_list<NODETYPE>::linked_list() {
        first = nullptr;
        current = nullptr;
        last = nullptr;
}

// destructor
template <class NODETYPE>
linked_list<NODETYPE>::~linked_list() {
        current = first;
        while (current != nullptr) {
                first = first->next;
                delete current;
                current = first;
        }
        current = last = first = nullptr;
}

// copy constructor
template <class NODETYPE>
linked_list<NODETYPE>::linked_list(linked_list<NODETYPE>& originalList) {
    first = new ListNode<NODETYPE>;
    current = new ListNode<NODETYPE>;
    last = new ListNode<NODETYPE>;
    *first = *(originalList.first);
    *current = *(originalList.current);
    *last = *(originalList.last);
}

/* 
Inserts a given node into the linked list, so that the 
list remains sorted.

@param value the node to insert.
@return bool whether the node was inserted.
*/
template <class NODETYPE>
bool linked_list<NODETYPE>::InsertInOrder(NODETYPE value)
{
    
	ListNode<NODETYPE>* newNode;
    newNode = new ListNode<NODETYPE>;
    current = first;
    
    // if memory for node allocated
    if (newNode != nullptr) {
        
        newNode->data = value;
		
        // if this is the first node to insert
        if (IsEmpty()) {
            InsertFront(value);
        }
            
        // if the new node data is less than first node
        else if (value < first->data) {
            InsertFront(value);
        }
        
        // if the new node data is greater than last node data
        else if (value >= last->data) {
            InsertRear(value);
        }
        else { // finds correct placement for node
            current = first;
            
            // finds the first node less than the node to insert
            while (current != nullptr && current->next->data < value) {
                current = current->next;
            }
            
            // connects the new node's next to current's next
            newNode->next = current->next;
            
            // connects current's next to the new node
            current->next = newNode;
        }
    }
    else {
        return false;
    }
    
    return true;
}

/* 
Inserts a given node to the front of the linked list.

@param value the node to insert.
@return bool whether the node was inserted.
*/
template <class NODETYPE>
bool linked_list<NODETYPE>::InsertFront(NODETYPE value) {
  
    current = new ListNode<NODETYPE>;
    
    // if memory not allocated
    if (current == nullptr) {
        return false;
    }
    else {
        current->data = value;
        
        // if this is the first node in the linked list
        if (first == nullptr) {
            first = current;
            last = current;
            current->next = nullptr;
        }
		
		// if the list is not empty
        else { 
            current->next = first;
            first = current;
        }
        return true;
    }
}

/* 
Inserts a given node to the end of the linked list.

@param value the node to insert.
@return bool whether the node was inserted.
*/
template <class NODETYPE>
bool linked_list<NODETYPE>::InsertRear(NODETYPE value) {
    
    current = new ListNode<NODETYPE>;
    
    // if memory not allocated
    if (current == nullptr) {
        return false;
    }
    else {

        current->data = value;
        
        // if this is the first node in the linked list
        if (first == nullptr) {
            first = current;
            last = current;
            current->next = nullptr;
        }
		
		// if the list is not empty
        else {
            last->next = current;
            current->next = nullptr;
            last = current;
        }
        return true;
    }
}

template <class NODETYPE>
bool linked_list<NODETYPE>::IsEmpty() const {
        return (first == NULL);
}

/* 
Finds a given node in a linked list. Returns the found
node by reference.

@param value the key to search by.
@return bool whether the node was found.
*/
template <class NODETYPE>
void linked_list<NODETYPE>::Search(NODETYPE& value) {
        
		// if list is empty, value not found
        if (IsEmpty()) {
            return;
        }
        else {
            current = first;
            
            //use a while loop to find value
            while (current != nullptr && current->data != value) {
                current = current->next;
            }
            
            //if current not null, value found
            if (current != nullptr) {
                value = current->data; // returns found node by reference
            }
        }
}

/* 
Prints the contents of all nodes in the linked list.
*/
template <class NODETYPE>
void linked_list<NODETYPE>::PrintAll() {
    
    if (!IsEmpty()) {
        
        current = first;
        
		// loops through all nodes
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }
}

/* 
Removes the head of the linked list. Returns the 
removed node by reference.

@param value the node to remove.
@return bool whether the node was removed.
*/
template <class NODETYPE>
bool linked_list<NODETYPE>::RemoveFront(NODETYPE& value) {
    current = first;
    
    // if list is empty
    if (current == nullptr) {
        return false;
    }
    else {
        value = first->data;
        delete first;
        first = current->next;
        return true;
    }
}

/* 
Removes the tail of the linked list. Returns the 
removed node by reference.

@param value the node to remove.
@return bool whether the node was removed.
*/
template <class NODETYPE>
bool linked_list<NODETYPE>::RemoveRear(NODETYPE& value) {
     current = first;
     
     // if list is empty
    if (current == nullptr) {
        return false;
    }
    // if first node is also last (only one node in list)
    if (value == first->data && first == last) {
        value = first->data;
        delete first;
        last = nullptr;
        first = nullptr;
        return true;
    }
    else { // if list has multiple nodes
        value = last->data;
        
		// finds node before last node
        while (current != nullptr && 
               current->next->data != value) {
            current = current->next;
        }
        
		// if last node found
        if (current != nullptr) {
            delete last;
            last = current;
            last->next = nullptr;
            return true;
        }
        else {
            return false;
        }
    }
}

/* 
Removes a given node in the linked list. Returns the 
removed node by reference.

@param value the node to remove.
@return bool whether the node was removed.
*/
template <class NODETYPE>
bool linked_list<NODETYPE>::Remove(NODETYPE& value) {
    
    // if given node is the first node
    if (value == first->data) {
        return RemoveFront(value);
    }
    
    // if given node is the last node
    else if (value == last->data) {
        return RemoveRear(value);
    }
    else {
       
        current = first;
        
        // finds node before given node
        while (current != nullptr && current->next->data != value) {
            current = current->next;
        }
        
        // if given node is not found
        if (current == nullptr) {
            return false;
        }
        else {
            // points to the node to delete
            ListNode<NODETYPE>* temp = current->next;
            value = temp->data;
            
            // removes given node
            current->next = temp->next;
            delete temp;
            return true;
        }
    }
    return true;
}

#endif /* LIST_CPP */
