#ifndef LISTNODE_H
#define LISTNODE_H
#include "ItemType.h"

struct ListNode {
   ListNode(ItemType i, ListNode *n)
   {
      item = i;
      n = next;
   }
    // Item Object
    ItemType item;
   
    // Next Pointer
    ListNode *next;
};

#endif
