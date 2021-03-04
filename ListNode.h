#ifndef LISTNODE_H
#define LISTNODE_H
#include "ItemType.h"

struct ListNode {

   // Default Constructor     
   ListNode();
   // ListNode Constructor
   ListNode(ItemType i, ListNode *n)
   {
      item = i;
   }
   // Item Object
   ItemType item;
   // Next Pointer
   ListNode *next;
   
}; //ListNode

#endif

