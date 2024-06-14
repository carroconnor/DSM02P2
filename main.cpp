#include <iostream>
#include <fstream>
#include <string>
#include "clock.h"
#include "orderedLinkedList.h"

/* Program name: yarn.cpp
* Author: Carr O'Connor
* Date last updated: 6/9/2024
* Purpose: Build yarn objects
*/

int main(){
    orderedLinkedList<clockType> list;
    clockType fam1 = clockType(23, 30, 30, TWENTYFOUR, AM);
    clockType fam2 = clockType(22, 15, 15, TWENTYFOUR, AM);
    clockType fam3 = clockType(0, 30, 14, TWENTYFOUR, AM);
    clockType fam4 = clockType(10, 9, 8, TWENTYFOUR, AM);
    clockType fam5 = clockType(15, 0, 0, TWENTYFOUR, AM);

    list.insert(fam1);
    list.insert(fam2);
    list.insert(fam3);
    list.insert(fam4);
    list.insert(fam5);

    std::ostream& os = std::cout;

    list.print(os);

    bool found = list.search(fam1);
    os.clear();
    os << found << std::endl;

    list.deleteNode(fam1);
    os.clear();
    list.print(os);

    return 0;
}