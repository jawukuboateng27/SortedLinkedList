#include <iostream>
#include <fstream>
#include "ItemType.h"

using namespace std;

ItemType::ItemType() {
    value = 0;
}

ItemType::ItemType(int value) {
    this -> value = value;
}

Comparison ItemType::compareTo(ItemType item) {
    if (this -> value > item.getValue()) {
	return GREATER;
    }

    else if (this -> value < item.getValue()) {
	return LESS;
    }

    else {
	return EQUAL;
    }
}

int ItemType::getValue() const {
    return value;
}

void ItemType::initialize(int num) {
    this -> value = num;
}
