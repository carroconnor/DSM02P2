#ifndef OLLIST_H
#define OLLIST_H

#include "linkedList.h"

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

template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem){
	node<Type>* newNode = new node<Type>();
    newNode->info = new Type(newItem);
    newNode->link = nullptr;

    if (this->first == nullptr || *newNode->info < *this->first->info) {
        newNode->link = this->first;
        this->first = newNode;
    } else {
        node<Type>* current = this->first;
        while (current->link && *current->link->info < *newNode->info) {
            current = current->link;
        }
        newNode->link = current->link;
        current->link = newNode;
    }
}

template <class Type>
bool orderedLinkedList<Type>::search(const Type &searchItem) const {
	node<Type>* temp = this->first;
    while (temp != nullptr) {
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
}

template <class Type>
void orderedLinkedList<Type>::insertLast(const Type &newItem){
	node<Type>* newNode = new node<Type>();
	newNode->info = new Type(newItem);
	if(this->last == nullptr){
		this->last = newNode;
		return;
	}
	node<Type> *temp = this->first;
	while (temp->link != nullptr)
	{
		temp = temp->link;
	}
	temp->link = newNode;
}

template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type &deleteItem){
	node<Type> *temp = this->first;
	node<Type> *prev = nullptr;
	while(temp != nullptr){
		if(*(temp->info) == deleteItem){
			if(prev == nullptr){
				this->first = temp->link;
				delete temp;
				return;
			}
			else{
				prev->link = temp->link;
				delete temp;
				return;
			}
		}
		else{
			temp = temp->link;
		}
	}
}

#endif