#include <iostream>

#include "SortedLinkedList.h"
#include "ListNode.h"

using namespace std;

// Constructor 
SortedLinkedList::SortedLinkedList() {
    head = nullptr;
    currentPos = nullptr;
    Length = 0;
} // SortedLinkedList

// Destructor
SortedLinkedList::~SortedLinkedList() {
    ListNode *current;

    // Iterate through LinkedList and delete all the nodes
    while(head != nullptr) {
        current = head;
        head = head->next;
        delete current;
    } 
} // SortedLinkedList

// Return the length of the linked list
int SortedLinkedList::length() const {
    return Length;
} // length

// Insert item to linked list
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
        }
        // Duplicate
        else if (item.compareTo(current->item) == ItemType::EQUAL) {
            cout << "\nSorry. You cannout insert the duplicate item.\n" << endl;
            isDuplicate = true;
            delete newNode;
            break;
        }
        else {
            break;
        }
    }

    if (prev == nullptr && !isDuplicate) {
        newNode->next = current;
        head = newNode;
        Length++;
    }

    else if (!isDuplicate) {
        prev->next = newNode;
        newNode->next = current;
        Length++;
    }
} // insertItem

// Delete an item from linked list
void SortedLinkedList::deleteItem(ItemType item) {
    ListNode *prev = nullptr;
    ListNode *current = head;

    // Empty List
    if(Length == 0) {
        cout<<"You cannot delete from an empty list"<<endl;
        return;
    }
    
    // Delete the first item
    if(item.compareTo(current->item) == ItemType::EQUAL) {
        head = current->next;
        Length--;
        delete current;
        return;
    }

    // Delete the only item
    if((item.compareTo(current->item) == ItemType::EQUAL) && (current->next == nullptr)) {
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
        else if (item.compareTo(current->item) == ItemType::EQUAL) {
            isFound = true;
            break;
        }
        else {
            break;
        }
    } // while

    if(isFound) {
        prev->next = current -> next;
        Length--;
        delete current;
    }
    else {
        cout<<"Item not found\n"<<endl;
    }
} // deleteItem

// Search the ListNode for an item
int SortedLinkedList::searchItem(ItemType item) {
    int index = 0;
    ListNode *current = head;

    // Iterate through LinkedList
    while(current!= nullptr) {
        
        // Item found
        if (item.compareTo(current->item) == ItemType::EQUAL) {
            return index;
        }

        // Iterate to next node
        else if(item.compareTo(current->item) == ItemType::GREATER) {
            current = current->next;
            index++;
        }
        
        // Compare to LESS
        else {
            break;
        }
    }

    // Item not found in search
    cout<<"Item not found\n"<<endl; //after comparing to LESS meaning item not in list
    return -1;
} // searchItem

// Returns the next item in the list pointed by thecurrentPos pointer
ItemType SortedLinkedList::GetNextItem() {
    ItemType item;

    // Empty list
    if(Length == 0) {
        cout<<"List is empty"<<endl;
        return item;
    }

    // End of the List
    else if (currentPos == nullptr || currentPos->next == nullptr) {
        // Set currentPos to index 0
        currentPos = head;
    }

    // Next Node
    else {
        currentPos = currentPos->next;
    }

    return currentPos->item;
} // GetNextItem

// Reset List
void SortedLinkedList::ResetList() {
    currentPos = nullptr;
} // ResetList

// Merge List
void SortedLinkedList::Merge(SortedLinkedList *list2) {
    bool check = false;

    for(int i = 0; i < list2->length(); i++) {
        if(this->searchItem(list2->currentPos->item) > -1) {
            check = true;
        }
        list2->currentPos = list2->currentPos->next;
    } // for

    list2->ResetList();
    ListNode *temp2 = new ListNode(list2->head->item, list2->head->next);

    if(check) {
        cout<<"Sorry. You cannot insert the duplicate item."<<endl;
        return;
    } // if

    else {
        while(temp2 != nullptr) {
            ItemType copy;
            int i = temp2->item.getValue();
            copy.initialize(i);

            this->insertItem(copy);
            if(temp2->next == nullptr) {
                return;
            }
            temp2 = temp2->next;
        } // while
    } // else

} //Merge

/*
// Return head
ListNode *SortedLinkedList::getHead() {
    return head;
}
*/

// Delete alternate nodes from the list
int SortedLinkedList::DeleteAlternateNodes(ItemType item) {
    ListNode *temp = this->head;
    int Length = this->length();

    // Length less than 2
    if(Length < 2) {
        cout<<"List length is not sufficient to apply this method."<<endl;
    }

    // Even Length
    if(Length%2 == 0) {
        // even case
        while (temp->next->next != nullptr) {
            deleteItem(temp->next->item);
            temp = temp->next;
        }
        deleteItem(temp->next->item);
    }

    // Odd length
    else {
        while (temp->next != nullptr) {
            deleteItem(temp->next->item);
            temp = temp->next;
        }
    }
} // DeleteAlternateNodes

// Find the common elements between input list and original list
ItemType SortedLinkedList::Intersection(SortedLinkedList *another) {
    SortedLinkedList *list = new SortedLinkedList();
    ListNode *temp = new ListNode(another->head->item, another->head->next);

    // Iterate through other list
    while(temp != nullptr) {
        if(this->searchItem(temp->item) != -1) {
            ItemType copy;
            int i = temp->item.getValue();
            copy.initialize(i);
            list->insertItem(copy);
        }
        
        if(temp->next == nullptr) {
            break;
        }

        temp = temp->next;
    } // while
    return list;
} // Intersection

// Print List Method
void SortedLinkedList::printList() {
    ResetList();
    
    for (int i = 0; i < Length; i++) {
        ItemType item = GetNextItem();
        cout << item.getValue() << " ";
    }
    
    cout << endl;
} // printList



