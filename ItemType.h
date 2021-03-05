#ifndef SORTEDLINKEDLISTBYLO_ITEMTYPE_H
#define SORTEDLINKEDLISTBYLO_ITEMTYPE_H
#include <iostream>
using namespace std;

enum Comparison{ GREATER, LESS, EQUAL };

class ItemType {

    int value;
public:
    //default constructor
    ItemType();
    /* compares the value of the item with the current objects value
     * returns GREATER, LESS or EQUAL
     */
    Comparison compareTo(ItemType item);
    //Returns the value instance variable
    int getValue() const;
    //Initializes the data member by variable num
    void initialize(int num);
};

#endif //SORTEDLINKEDLISTBYLO_ITEMTYPE_H
