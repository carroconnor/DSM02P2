#ifndef OLLIST_H
#define OLLIST_H

#include "linkedList.h"

template <class Type>
class orderedLinkedList : public linkedList<Type>
{
public:
	void insert(const Type &newITem) = 0;
};

template <class Type>
void orderedLinkedList<Type>::insert(const Type &newItem){
	node<Type>* newNode = new node<Type>(newItem);
	if(!this->first || newItem < this->head->info){
		newItem->link = this->head;
		this->head = newItem;
	} else {
		node<Type>* current = this->head;
		while(current->next != nullptr && current->link->info < newItem){
			current = current->link;
		}
		newItem->link = current->link;
		cuurent->link = newItem;
	}
}

#endif