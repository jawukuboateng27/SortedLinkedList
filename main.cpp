#include <iostream>
#include "ItemType.h"
#include "ListNode.h"
#include "SortedLinkedList.h"
#include <fstream>
#include <string>

using namespace std;

// Main that runs the program.
    SortedLinkedList *inputList(int length){
        SortedLinkedList *newList = new SortedLinkedList();




    }
int main(int argc, char** argv){
    SortedLinkedList list;
    ItemType item;
    int input;
    fstream fs;

    fs.open(argv[1], fstream::in);
    if (fs.is_open())
    {
        fs >> input;
        while (!fs.eof())
        {
            item.initialize(input);
            list.insertItem(item);
            fs >> input;
        }
    }
    else
    {
        cout << "Failed to open the input file" << std::endl;
        return 0;
    }
    string command = "";
    while(command != "q"){
        //main
        cout << "Commands:" << endl;
        cout << "(i) - Insert value" << endl;
        cout << "(d) - Delete value" << endl;
        cout << "(s) - Search value" << endl;
        cout << "(n) - Print next iterator value" << endl;
        cout << "(r) - Reset iterator" << endl;
        cout << "(a) - Delete alternate nodes" << endl;
        cout << "(m) - Merge two lists" << endl;
        cout << "(t) - Intersection" << endl;
        cout << "(p) - Print list" << endl;
        cout << "(l) - Print length" << endl;
        cout << "(q) - Quit program" << endl;

        cout << "Enter a command: ";
        cin >> command;

        if(command == "i"){
            list.print();
            cout << "Enter a number: ";
            cin >> input;
            cout << endl;
            item.initialize(input);
            list.insertItem(item);
            list.print();
        }

        else if(command == "d"){
            list.print();
            cout << "Enter value to delete: ";
            cin >> input;
            cout << endl;
            item.initialize(input);
            list.deleteItem(item);
            list.print();
        }

        else if(command == "s"){
            cout << "Enter a value to search: ";
            cin >> input;
            item.initialize(input);
            int returnValue = list.searchItem(item);
            if(returnValue == -1){
                cout << "Item not found" << endl;
            }
            else{
                cout << "Index " << returnValue << endl;
            }
        }

        else if(command == "p"){
            list.print();
        }

        else if(command == "r"){
            list.resetIterator();
            cout << "Iterator reset" << endl;
        }

        else if(command == "a") {
            list.deleteAlternateNodes();
            list.print();
        }

        else if(command == "l"){
            cout << "List length is " << list.length() << endl;
        }

        else if(command == "n"){
            if(list.length() == 0){
                cout << "List is empty" << endl;
            }
            else{
                item = list.GetNextItem();
                cout << item.getValue() << endl;
            }
        }
        else if(command == "q"){
            break;
        }

        else if(command == "m"){
           SortedLinkedList *list2;
           cout<<"Length of list to merge: ";
           int length;
           cin>>length;
           if(cin.fail()){
               cout<<"Please enter an integer next time"<<endl;
                break;
           }
           list2 = inputList(length);
           cout<<"List 1: ";
           list.print();
           cout<<"List 2: ";
            list2->print();
            list.Merge(list2);
            list.print();
        }
        else{
            cout << "Invalid command, try again!" << endl;
        }

    }

}
