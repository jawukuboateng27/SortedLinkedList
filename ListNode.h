#ifndef LISTNODE_H
#define LISTNODE_H
#include "ItemType.h"

struct ListNode {

   // Public Variables
   public:
        // Item Object
        ItemType item;
        // Next Pointer
        ListNode *next;
};

#endif
