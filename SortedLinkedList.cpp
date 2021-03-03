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
            if (item.compareTo(current->item) == ItemType::GREATER) {
                prev = current;
                current = current->next;
            } else if (item.compareTo(current->item) == ItemType::EQUAL) {
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
        if(item.compareTo(current->item)== ItemType::EQUAL)
        {
            head = current->next;

            Length--;

            delete current;

            return;
        }

        //deleting the only item
        if((item.compareTo(current->item)==ItemType::EQUAL) && (current->next == nullptr))
        {
            Length--;

            delete current;

            head = nullptr;

            return;
        }
        bool isFound = false;

        while(current != nullptr) {
            if (item.compareTo(current->item) == ItemType::GREATER) {
                prev = current;
                current = current->next;
            }
            else if (item.compareTo(current->item) == ItemType::EQUAL)
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
            if(item.compareTo(current->item)==ItemType::GREATER)
            {
                current = current->next;
                index++;
            }
            else if(item.compareTo(current->item)==ItemType::EQUAL)
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
        if(currentPos == nullptr){
            currentPos = head;

        //prepare item to be returned and advance pointer
        item = currentPos->item;
        currentPos = currentPos->next;
       }
        return item;
    }

    void SortedLinkedList::ResetList()
    {
        currentPos = nullptr;
    }

     void SortedLinkedList::Merge(SortedLinkedList *list2)
    {
        bool check = false;
        for(int i = 0; i < list2->length(); i++)
        {
            if(this->searchItem(list2->currentPos->item) > -1)
            {
                check = true;
            }
            list2->currentPos = list2->currentPos->next;
        }
            list2->ResetList();
        ListNode *temp2 = new ListNode(list2->getHead()->item, list2->getHead()->next);
        int cont;
        if(check)
        {
            cout<<"Sorry. You cannot insert the duplicate item."<<endl;
            return;
        }
        else
        {
            while(temp2 != nullptr)
            {
                ItemType copy;
                int i = temp2->item.getValue();
                copy.initialize(i);

                this->insertItem(copy);
                if(temp2->next == nullptr)
                {
                    return;
                }
                temp2 = temp2->next;
            }
        }
    }

    ListNode *SortedLinkedList::getHead()
    {
        return head;
    }

        
    void SortedLinkedList::DeleteAlternateNodes(ItemType item)
    {

        ListNode *temp = this->head;
        int Length = this->length();
        //check length of list
        if(Length < 2)
        {
            cout<<"List length is not sufficient to apply this method."<<endl;
            return;
        }

        if(Length%2 == 0)
        {
            // even case
            while (temp->next->next != nullptr)
            {
                deleteItem(temp->next->item);
                temp = temp->next;
            }
            deleteItem(temp->next->item);
        }
        else
        {
            // odd case
            while (temp->next != nullptr)
            {
                deleteItem(temp->next->item);
                temp = temp->next;
            }
        }
    }

    SortedLinkedList *SortedLinkedList::Intersection(SortedLinkedList *another)
    {
        SortedLinkedList *list = new SortedLinkedList();
        ListNode *temp = new ListNode(another->getHead()->item, another->getHead()->next);

        //iterate through other list
        while(temp != nullptr)
        {
            if(this->searchItem(temp->item) != -1)
            {
                ItemType copy;
                int i = temp->item.getValue();
                copy.initialize(i);
                list->insertItem(copy);
            }
            if(temp->next == nullptr)
                break;
            temp = temp->next;
        }
        return list;
    }

    void SortedLinkedList::printList()
    {
        ResetList();

        for(int i = 0; i < Length; i++) {
            ItemType item = GetNextItem();

            cout << item.getValue() << " ";
        }

        cout << endl;
    }



