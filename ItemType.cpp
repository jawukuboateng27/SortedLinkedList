#include<iostream>
#include "ItemType.h"

using namespace std;

// Default Constructor
ItemType::ItemType() {
    value = 0;
}

// Constructor
ItemType::ItemType(int value) {
    this->value = value;
}

// Value Comparison Method
Comparison ItemType::compareTo(ItemType item) {
    // Parameter value is less than the current object's value
    if (value < item.value) {
        return LESS;
    }
    // Parameter value is greater than the current object's value
    else if (value > item.value) {
        return GREATER;
    }
    // Parameter value is equal to the current object's value
    else {
        return EQUAL;
    }
}
    
// Return the value instance variable
int ItemType::getValue() const {
    return value;
}

//  Initializes the data member by variable num
void ItemType::initialize(int num) {
    this->value = num;
}

