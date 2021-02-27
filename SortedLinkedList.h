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
            ItemType Merge();
            int DeleteAlternateNodes(ItemType item);
            int Intersection();

    private:
            ListNode *head;
            ListNode *currentPos;
            int Length;


};

