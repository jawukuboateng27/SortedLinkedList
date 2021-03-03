#include "ListNode.h"
#include "ItemType.h"

class SortedLinkedList
    {
    public:
            SortedLinkedList();
            ~SortedLinkedList();
            int length()const;
            void insertItem(ItemType item);
            void deleteItem(ItemType item);
            int searchItem(ItemType item);
            ItemType GetNextItem();
            void ResetList();
            ItemType Merge(ItemType item);
            void DeleteAlternateNodes(ItemType item);
            int Intersection();
            void printList();

    private:
            ListNode *head;
            ListNode *currentPos;
            int Length;


};

