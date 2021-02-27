#include<iostream>
#include "ItemType.h"

    Comparison ItemType::compareTo(ItemType item)
    {
          if(value < item.value){
                return LESS;
          }else if (value > item.value){
                return GREATER;
          }else
              return EQUAL;
    }

    int ItemType::getValue() const
    {
        return value;
    }

    void ItemType::initialize(int num)
    {
        this->value = num;
    }

