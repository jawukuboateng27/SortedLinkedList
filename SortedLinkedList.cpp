    #include "SortedLinkedList.h"
    #include "ItemType.h"
    #include <iostream>

    using namespace std;

    SortedLinkedList::SortedLinkedList(){
        this->listLength = 0;
        this->head = 0;
        this->currentPos = head;
        this->iterator = head;
    }

    SortedLinkedList::~SortedLinkedList(){
        currentPos = head;
        if(this->listLength == 1){
            currentPos = NULL;
            delete currentPos;
        }
        while(currentPos->next!= head){
            currentPos = currentPos->next;
            delete currentPos;
            this->listLength--;
        }
    }
    int SortedLinkedList::length() const{
        return this->listLength;
    }

    void SortedLinkedList::insertItem(ItemType item){
        ListNode *tempNode = new ListNode;
        tempNode->item = item;

        if(this->listLength == 0){
            tempNode->next = tempNode;
            head = tempNode;
            this->listLength++;
        }
        else{
            currentPos = head;
            iterator = head;
            for(int i = 0; i < this->listLength;i++){
                if(currentPos == head && (currentPos->item.compareTo(item) == GREATER)){
                    while(currentPos->next != head){
                        currentPos = currentPos->next;
                    }
                    currentPos->next = tempNode;
                    tempNode->next = head;
                    head = tempNode;
                    this->listLength++;
                    break;
                }
                else if(currentPos->item.compareTo(item) == EQUAL){
                    cout << "Sorry. You cannot insert the duplicate item" << endl;
                    break;
                }
                else if((item.compareTo(currentPos->item) == GREATER) && (currentPos->next == head)){
                    currentPos->next = tempNode;
                    tempNode->next = head;
                    this->listLength++;
                    break;
                }

                else if((currentPos->item.compareTo(item) == LESS) && (currentPos->next->item.compareTo(item)
                                                                       == GREATER)){
                    tempNode->next = currentPos->next;
                    currentPos->next = tempNode;
                    this->listLength++;
                    break;
                }
                else{
                    currentPos = currentPos->next;
                }
            }
        }

    }

    void SortedLinkedList::deleteItem(ItemType item){
        if(this->listLength == 0){
            cout << "You cannot delete from an empty list" << endl;
            return;
        }
        else{
            bool found = false;
            currentPos = head;
            if(currentPos->item.compareTo(item)== EQUAL && listLength == 1){
                currentPos = NULL;
            }
            for(int i = 0; i <= this->listLength;i++){
                if(currentPos->item.compareTo(item) == EQUAL){
                    if(currentPos == head){
                        head = currentPos->next;
                        delete currentPos;
                        this->listLength--;
                        found = true;
                        break;
                    }
                }
                else if((currentPos->next->item.compareTo(item) == EQUAL) && (currentPos->next->next == head)){ //Modified line
                    delete currentPos->next;
                    currentPos->next = head;
                    this->listLength--;
                    found = true;
                    break;
                }
                else if((currentPos->next->item.compareTo(item) == EQUAL) && (currentPos->next->next != head)){
                    ListNode* temp = currentPos->next;
                    temp = currentPos->next;
                    currentPos->next = currentPos->next->next;
                    delete temp;
                    this->listLength--;
                    found = true;
                    break;
                }
                else{
                    currentPos = currentPos->next;
                }
            }
            if(found == false){
                cout << "Item not found!" << endl;
            }
        }

    }

    int SortedLinkedList::searchItem(ItemType item){
        currentPos = head;
        int count  = 0;
        while(currentPos->next != head){
            if(currentPos->item.compareTo(item) == EQUAL){
                return count;
            }
            else{
                currentPos = currentPos->next;
                count++;
            }
        }
        return -1;
    }

    ItemType SortedLinkedList::GetNextItem(){
        ItemType returnType;
        returnType = iterator->item;
        iterator = iterator->next;
        return returnType;
    }

    void SortedLinkedList::ResetList(){
        this->listLength = 0;
        this->head = NULL;
    }

    void SortedLinkedList::print(){
        currentPos = head;
        if(this->listLength == 0){
            return;
        }
        do{
            cout<< currentPos->item.getValue() << " ";
            currentPos = currentPos->next;
        } while((currentPos != head) && (currentPos->item.getValue() != 0));
        cout << endl;


    }

    void SortedLinkedList::resetIterator(){
        this->iterator = head;
    }

    void SortedLinkedList::deleteAlternateNodes() {
        ItemType k;
        currentPos = head->next;
    }

    void SortedLinkedList::Merge(SortedLinkedList *list2) {
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
        ListNode *temp2 = new ListNode();
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

    SortedLinkedList *SortedLinkedList::intersection(SortedLinkedList *another)
    {
        SortedLinkedList *list = new SortedLinkedList();
        ListNode *temp = new ListNode(another->getHead()->item, another->getHead()->next);
        while(temp != nullptr){
            if(this->searchItem(temp->item)!= -1)
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

    ListNode *SortedLinkedList::getHead(){
        return head;
    }