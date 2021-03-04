#include "ItemType.h"
#include "ListNode.h"

class SortedLinkedList {
 public:
    SortedLinkedList();
    ~SortedLinkedList();
    int length() const;
    void insertItem(ItemType item);
    void deleteItem(ItemType item);
    void deleteItem(int index);
    int searchItem(ItemType item);
    ItemType searchItem(int index);
    ItemType GetNextItem();
    void ResetList();
    void DeleteAlternateNodes(ItemType item);
    ListNode* findPrevNode(ListNode* node);
    ListNode* getLastNode();
    void printList();
    
 private:
    ListNode* head;
    ListNode* currentPos;
    int lengthValue;
};
