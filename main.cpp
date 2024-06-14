#include <iostream>
#include <fstream>
#include <string>
#include "orderedLinkedList.h"
#include "person.h"

/* Program name: yarn.cpp
* Author: Carr O'Connor
* Date last updated: 6/9/2024
* Purpose: Build yarn objects
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

    list.print(os);

    list.insertFirst(Person("Test", 0));
    list.insertLast(Person("Test", 100));
    
    os.clear();
    list.print(os);

    bool found = list.search(fam1);
    os.clear();
    os << found << std::endl;

    list.deleteNode(fam1);
    os.clear();
    list.print(os);

    return 0;
}