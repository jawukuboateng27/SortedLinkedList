#include <iostream>

#include "SortedLinkedList.h"

using namespace std;

SortedLinkedList::SortedLinkedList() {
    head = nullptr;
    currentPos = nullptr;
    lengthValue = 0;
}

SortedLinkedList::~SortedLinkedList() {
    ListNode* current;

    // iterate through the list and delete all the nodes
    while(head != nullptr) {
	current = head;
	head = head->next;
	delete current;
    }
}

int SortedLinkedList::length() const {
    return lengthValue; // a length variable will be used for the length
}

void SortedLinkedList::insertItem(ItemType item) {
    ListNode* newNode = new ListNode;
    newNode->item = item;
    
    ListNode* prev = nullptr;
    ListNode* current = head;

    bool isDuplicate = false;
    while(current != nullptr) {
	if(item.compareTo(current->item) == GREATER) { // keep going
	    prev = current;
	    current = current->next;
	}

	else if(item.compareTo(current->item) == EQUAL) { // duplicate item
	    cout << "\nSorry. You cannot insert the duplicate item\n" << endl;
	    isDuplicate = true;
	    delete newNode; // delete the unused new node to avoid a memory leak
	    break;
	}

	else // found the location to insert item
	    break;
    }

    // if newNode is being inserted into the very beginning or is being inserted to empty list
    if(prev == nullptr && !isDuplicate) {
	newNode->next = current;
	head = newNode;
	lengthValue++;
    }

    else if(!isDuplicate) { // general case insert
	prev->next = newNode;
	newNode->next = current;
	lengthValue++;
    }
}

void SortedLinkedList::deleteItem(ItemType item) {
    ListNode* prev = nullptr;
    ListNode* current = head;

    if(head == nullptr) { // list is empty
	cout << "You cannot delete from an empty list" << endl;

	return;
    }

    if(item.compareTo(current->item) == EQUAL) { // deleting the first item
	head = current->next;

	lengthValue--;

	delete current;

	return;
    }

    // deleting the only item
    if((item.compareTo(current->item) == EQUAL) && (current->next == nullptr)) {
	lengthValue--;

	delete current;

	head = nullptr;

	return;
    }
    
    bool isFound = false;
    while(current != nullptr) {
	if(item.compareTo(current->item) == GREATER) { // keep going
	    prev = current;
	    current = current->next;
	}

	else if(item.compareTo(current->item) == EQUAL) { // item found
	    isFound = true;
	    
	    break;
	}

	else // if given item is less than current item has not been found by now, item isn't in list
	    break;
    }

    if(isFound) { // general case delete
	prev->next = current->next;
    
	lengthValue--;
   
	delete current;
    }

    else
	cout << "Item not found\n" << endl;
}

// same as the other deleteItem, but works with the given index integer
void SortedLinkedList::deleteItem(int index) {
    deleteItem(searchItem(index));
}

int SortedLinkedList::searchItem(ItemType item) {
    int index = 0;

    ListNode* current = head;
    while(current != nullptr) {
	if(item.compareTo(current->item) == GREATER) { // item is further down the list
	    current = current->next;
	    index++;
	}

	else if(item.compareTo(current->item) == EQUAL) // item has been found
	    return index;

	else // aka compareTo == LESS, which means item is not in list and has not been found
	    break;
    }

    cout << "Item not found\n" << endl;

    return -1;
}

// like the other searchItem, but returns an ItemType given an index integer
ItemType SortedLinkedList::searchItem(int index) {
    ItemType item;

    // index is out of bounds or list is empty 
    if(index < 0 || index > lengthValue-1 || head == nullptr) {
	cout << "Item not found" << endl;

	return item;
    }

    ListNode* current = head;
    int i = 0;
    while(current != nullptr) {
	if(i == index) // found item
	    return current->item;

	current = current->next;
	i++;
    }

    return item;
}

ItemType SortedLinkedList::GetNextItem() {
    ItemType item;

    if(head == nullptr) { // list is empty
	cout << "List is empty" << endl;

	return item;
    }

    if(currentPos != nullptr) {
	// if the pointer is about to reach the end, go back to the beginning
	if(currentPos->next == nullptr) {
	    item = currentPos->item;
	    currentPos = head;

	    return item;
	}
    }

    // if currentPos is null, set to head so it can be used
    if(currentPos == nullptr)
	currentPos = head;

    // prepare item to be returned and advance the pointer
    item = currentPos->item;
    currentPos = currentPos->next;

    return item;
}

void SortedLinkedList::ResetList() {
    currentPos = nullptr;
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



// A helper function that iterates through the list and finds the previous node
// of the given node. Used in the reverse() function
ListNode* SortedLinkedList::findPrevNode(ListNode* node) {
    ListNode* prev = nullptr;
    ListNode* current = head;

    while(current->next != nullptr) {
	if(current == node)
	    return prev;

	prev = current;
	current = current->next;
    }

    return prev;
}

void SortedLinkedList::printList() {
    ResetList();
    
    for(int i = 0; i < lengthValue; i++) {
	ItemType item = GetNextItem();

	cout << item.getValue() << " ";
    }

    cout << endl;
}
