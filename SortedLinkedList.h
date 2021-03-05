#ifndef SORTEDLINKEDLISTBYLO_SORTEDLINKEDLIST_H
#define SORTEDLINKEDLISTBYLO_SORTEDLINKEDLIST_H
#include <iostream>
#include "ItemType.h"
#include "ListNode.h"

class SortedLinkedList{
    ListNode *head;
    ListNode *currentPos;
    ListNode *iterator;
    int listLength;
public:
    /**
     * Initialize a sorted linked list object
     */
    SortedLinkedList();
    /**
     * Deconstructor for sorted linked list object
     */
    ~SortedLinkedList();
    /**
     * Returns the length of the list object
     */
    int length() const;
    /**
     * Inserts the item at the correct spot in the list, unless duplicate
     */
    void insertItem(ItemType item);
    /**
     * Deletes the item with the equal value as the item below.
     */
    void deleteItem(ItemType item);
    /**
     * Searches for the item in the parameter, returning the index or "Item not Found"
     */
    int searchItem(ItemType item);
    /**
     * Returns the next item in the list, or a statement saying the list has reached its end.
     */
    ItemType GetNextItem();
    /**
     * Initializes the currentPos pointer to null.
     */
    void ResetList();
    //prints list
    void print();
    //resets iterator
    void resetIterator();

    void deleteAlternateNodes();
    void Merge(SortedLinkedList *list2);
//    void intersection(SortedLinkedList s);

    ListNode *getHead();

    SortedLinkedList *intersection(SortedLinkedList *another);
};
#endif //SORTEDLINKEDLISTBYLO_SORTEDLINKEDLIST_H
