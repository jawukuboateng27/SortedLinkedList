#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include "ListNode.h"
#include "ItemType.h"

class SortedLinkedList {
    
    // Public Variables
    public:
        // Deafult Constructor
        SortedLinkedList();
        // Method free up all the user allocated memory and destruct theSortedLinkedList instance
        ~SortedLinkedList();
        // Return the length of the linked list
        int length()const;
        // Method to insert item to linked list
        void insertItem(ItemType item);
        // Method to delete an item from linked list
        void deleteItem(ItemType item);
        // Method to search the ListNode for an item
        int searchItem(ItemType item);
        // Returns the next item in the list pointed by thecurrentPos pointer
        ItemType GetNextItem();
        // Method to initialize the currentPos pointer to null.
        void ResetList();
        // Method to merge the input list to the original list
        void Merge(SortedLinkedList *list);
        // Method to delete alternate nodes from the list
        int DeleteAlternateNodes(ItemType item);
        // Method to find the common elements between input list and original list
        ItemType Intersection(SortedLinkedList *list);
        // Method to print list
        void printList();
        // Method to return head
        //ListNode getHead();

    // Private Variables
    private:
        // Length
        int Length;
        // Pointer to head
        ListNode *head;
        // Pointer to currentPos
        ListNode *currentPos;
};
#endif
