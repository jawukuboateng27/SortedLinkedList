#ifndef ITEMTYPE_H
#define ITEMTYPE_H

enum Comparison{GREATER,LESS,EQUAL};

class ItemType {
   
   // Public Variables
   public:
      // Default constructor
      ItemType();
      // Value Comparison Method
      Comparison compareTo(ItemType item);
      // Value Getter Method
      int getValue()const;
      // Variable Initializing Method
      void initialize(int num);
   
   // Private Variables
   private:
      // Value
      int value;
};

#endif
