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

}

#endif