#include "ItemType.h"
using namespace std;

ItemType::ItemType(){
    this->value = 0;
}

enum Comparison ItemType::compareTo(ItemType item){
    enum Comparison returnComparison = GREATER;
    if(item.getValue() == this->getValue()){
        returnComparison = EQUAL;
    }
    else if(item.getValue() > this->getValue()){
        returnComparison = LESS;
    }
    return returnComparison;
}

int ItemType::getValue()const{
    return this->value;
}

void ItemType::initialize(int num) {
    this->value = num;
}
