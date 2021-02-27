#include <iostream>

#include "SortedLinkedList.h"


    using namespace std;

    SortedLinkedList::SortedLinkedList()
    {
        head = nullptr;
        currentPos = nullptr;
        Length = 0;
    }

    SortedLinkedList::~SortedLinkedList()
    {
        ListNode* current;
        // go through the list and delete all the nodes
        while(head != nullptr) {
            current = head;
            head = head->next;
            delete current;
        }
    }

    int SortedLinkedList::length() const
    {
        return Length;
    }

    void SortedLinkedList::insertItem(ItemType item) {
        ListNode *newNode = new ListNode;
        newNode->item = item;
        ListNode *prev = nullptr;
        ListNode *current = head;

        bool isDuplicate = false;
        while (current != nullptr) {
            if (item.compareTo(current->item) == GREATER) {
                prev = current;
                current = current->next;
            } else if (item.compareTo(current->item) == EQUAL) {
                cout << "\nSorry. You cannout insert the duplicate item.\n" << endl;
                isDuplicate = true;
                delete newNode;
                break;
            } else
                break;

        }
        if (prev == nullptr && !isDuplicate) {
            newNode->next = current;
            head = newNode;
            Length++;
        } else if (!isDuplicate) {
            prev->next = newNode;
            newNode->next = current;
            Length++;
        }
    }

    //trying to delete from an empty list
    void SortedLinkedList::deleteItem(ItemType item)
    {
        ListNode *prev = nullptr;
        ListNode *current = head;

        if(head == nullptr)
        {
            cout<<"You cannot delete from an empty list"<<endl;
            return;
        }
        //deleting the first item
        if(item.compareTo(current->item)== EQUAL)
        {
            head = current->next;

            Length--;

            delete current;

            return;
        }

        //deleting the only item
        if((item.compareTo(current->item)==EQUAL) && (current->next == nullptr))
        {
            Length--;

            delete current;

            head = nullptr;

            return;
        }
        bool isFound = false;

        while(current != nullptr) {
            if (item.compareTo(current->item) == GREATER) {
                prev = current;
                current = current->next;
            }
            else if (item.compareTo(current->item) == EQUAL)
            {
                isFound = true;

                break;
            }
            else
                break;
        }

            if(isFound)
            {
                prev->next = current -> next;
                Length--;
                delete current;
            }else
                cout<<"Item not found\n"<<endl;


    }

    int SortedLinkedList::searchItem(ItemType item)
    {
        int index = 0;
        ListNode *current = head;
        while(current!= nullptr)
        {
            if(item.compareTo(current->item)==GREATER)
            {
                current = current->next;
                index++;
            }
            else if(item.compareTo(current->item)==EQUAL)
            {
                return index;
            }
            else //compares to LESS
                break;
        }
        cout<<"Item not found\n"<<endl; //after comparing to LESS meaning item not in list
        return -1;
    }

    ItemType SortedLinkedList::GetNextItem()
    {
        ItemType item;

        if(head == nullptr)
        {
            cout<<"List is empty"<<endl;

            return item;
        }
        if(currentPos != nullptr)
        {
            //before pointer gets to the end it should go back to the beginning
            if(currentPos->next == nullptr)
            {
                item = currentPos->item;
                currentPos = head;

                return item;
            }
        }
        //if currentPos is null, set to head
        if(currentPos == nullptr)
            currentPos = head;

        //prepare item to be returned and advance pointer
        item = currentPos->item;
        currentPos = currentPos->next;
        return item;
    }

    void SortedLinkedList::ResetList()
    {
        currentPos = nullptr;
    }

    ItemType SortedLinkedList::Merge()
    {

    }
    int SortedLinkedList::DeleteAlternateNodes(ItemType item)
    {
        ListNode *current = head;
        ListNode *last;
        int index = 1;
        while(current != nullptr)
        {
                current = head;
                last = current->next;
                last->next = nullptr;
                index++;

                if(index % 2 == 0)
                {
                    delete current;
                    Length--;
                } else
                    break;

        }

    }

    int SortedLinkedList::Intersection()
    {
        
    }



