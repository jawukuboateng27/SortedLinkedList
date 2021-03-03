#ifndef ITEMTYPE_H
#define ITEMTYPE_H


class ItemType {
   
   // Public Variables
   public:
      // Default constructor
      ItemType();
      // Value Comparison Method
      enum Comparison{GREATER,LESS,EQUAL};
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
