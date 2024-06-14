#include <iostream>
#include <fstream>
#include <string>
#include "orderedLinkedList.h"
#include "person.h"

/* Program name: orderedLinkedList.cpp
* Author: Carr O'Connor
* Date last updated: 6/14/2024
* Purpose: build a templated linked list
*/

int main(){
    orderedLinkedList<Person> list;
    Person fam1 = Person("Carr", 31);
    Person fam2 = Person("Kevin", 22);
    Person fam3 = Person("Caroline", 28);
    Person fam4 = Person("Sarah", 30);
    Person fam5 = Person("Cali", 30);

    list.insert(fam1);
    list.insert(fam2);
    list.insert(fam3);
    list.insert(fam4);
    list.insert(fam5);

    std::ostream& os = std::cout;
    os << "Ordered Linked List: \n";
    list.print(os);
    os.clear();

    os << "\nSearching for item ... \n";
    bool found = list.search(fam1);
    if(found) os << "Item found! \n";
    else os << "Item not found! \n";

    os << "\nDeleting item... \n"; 
    list.deleteNode(fam1);
    os << "Item deleted! \n\nOrdered Linked List: \n";

    os.clear();
    list.print(os);

    return 0;
}