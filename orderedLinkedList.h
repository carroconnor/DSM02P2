#ifndef OLLIST_H
#define OLLIST_H

#include "linkedList.h"

//template the class so generic types can use and compilier can create code needed while we only worry about one area
template <class Type>
class orderedLinkedList : public linkedList<Type>
{
public:
	void insert(const Type& newITem);
    bool search(const Type &searchItem) const;
	void insertFirst(const Type &newItem);
	void insertLast(const Type &newItem);
	void deleteNode(const Type &deleteItem);
};

//insert function that that keeps track of first and last
template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem){
    if (this->first == nullptr || newItem < *this->first->info) {
        insertFirst(newItem);
    } else{
		node<Type>* current = this->first;
		while (current->link && *current->link->info < newItem) {
			current = current->link;
		}
		if(current->link == nullptr){
			insertLast(newItem);
		}
		else{
			node<Type>* newNode = new node<Type>();
			newNode->info = new Type(newItem);
			newNode->link = current->link;
			current->link = newNode;
			if(newNode->link == nullptr){
				this->last = newNode;
			}
		}
    }
}

//search for item in linked list
template <class Type>
bool orderedLinkedList<Type>::search(const Type &searchItem) const {
	node<Type>* temp = this->first;
    while (temp != nullptr) {
        //dereference to compare items
        if (*(temp->info) == searchItem) { 
            return true;
        }
        temp = temp->link;
    }
    return false;
}

template <class Type>
void orderedLinkedList<Type>::insertFirst(const Type &newItem){
	node<Type>* newNode = new node<Type>();
	newNode->info = new Type(newItem);
	newNode->link = this->first;
	this->first = newNode;
    //also set to last if null
	if (this->last == nullptr) { 
        this->last = newNode;
    }
}

template <class Type>
void orderedLinkedList<Type>::insertLast(const Type &newItem){
	node<Type>* newNode = new node<Type>();
    newNode->info = new Type(newItem);
    newNode->link = nullptr;
    if (this->last == nullptr) {
        this->first = this->last = newNode;
    } else {
        this->last->link = newNode;
        this->last = newNode;
    }
}

template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type &deleteItem){
	node<Type> *temp = this->first;
    node<Type> *prev = nullptr;
    while (temp != nullptr) {
        //dereference to compare items
        if (*(temp->info) == deleteItem) {
            if (prev == nullptr) {
                this->first = temp->link;
                if (this->first == nullptr) {
                    this->last = nullptr;
                }
                delete temp;
            } else {
                prev->link = temp->link;
                if (temp->link == nullptr) {
                    this->last = prev;
                }
                delete temp;
            }
            return;
        } else {
            prev = temp;
            temp = temp->link;
        }
    }
}

#endif