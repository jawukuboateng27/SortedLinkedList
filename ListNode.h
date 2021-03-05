#ifndef SORTEDLINKEDLISTBYLO_LISTNODE_H
#define SORTEDLINKEDLISTBYLO_LISTNODE_H


#include "ItemType.h"

struct ListNode{
    ListNode(ItemType type, ListNode *pNode);
    ListNode();
    ItemType item;
    ListNode *next;
};

#endif //SORTEDLINKEDLISTBYLO_LISTNODE_H
