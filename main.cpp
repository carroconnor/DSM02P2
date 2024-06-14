// For this assignment, you will start by creating an ordered linked list. To create the ordered linked list start with the linked list ADT. 
// Name your class orderedLinkedList. It should be templated. You will need to implement a method insert that finds the correct location to insert an item in the ordered linked list. 

// In the starter code, you will be given 3 classes. Each of the 3 classes overrides the comparison operators. 
// Pick one of the 3 and write a main that gets the data for 5 objects of your chosen class and insert them into an ordered linked list.
// Display the linked list before exiting.

// Since everyone will have different interfaces for their program depending on their chosen class, you will need to create 3 files of test input. 
// You will put your test input for the first test into input1.txt, the test input for the second test into input2.txt, and the test input for the third test into input3.txt. 
// Make sure you input the data in a random order. These input files will be used to run your code in CodeGrade. 
// Points will be manually awarded based on how well your ordered linked list puts the items in your test data in order. 

// There will also be a small unit test. If you name the templated class orderedLinkedList, extend the LinkedList class provided in the starter code, 
// and implement the insert function, then the unit tests should be able to run and test your code.

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
    orderedLinkedList<Person> *list;
    Person fam1 = Person("Carr", 31);
    Person fam2 = Person("Sarah", 30);
    Person fam3 = Person("Cali", 30);
    Person fam4 = Person("Caroline", 28);
    Person fam5 = Person("Kevin", 22);

    list->insert(fam1);
    list->insert(fam2);
    list->insert(fam3);
    list->insert(fam4);
    list->insert(fam5);

    std::ostream& os = std::cout;

    list->print(os);

    return 0;
}