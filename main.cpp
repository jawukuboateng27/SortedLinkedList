#include <iostream>
#include <fstream>
#include <string>
#include "SortedLinkedList.h"
#include "ItemType.h"

using namespace std;



    int main(int argc, char *argv[])
    {
        SortedLinkedList list;
        ItemType item;
        int input;
        fstream fs;
        fs.open(argv[1], fstream::in);
        if(fs.is_open()) {
            fs >> input;
            while (!fs.eof()) {
                item.initialize(input);
                list.insertItem(item);
                fs >> input;
            }
            cout <<(
                    "(i) - Insert value"
                    "\n(d) - Delete value"
                    "\n(s) - Search value"
                    "\n (n) - Print next iterator value"
                    "\n(r) - Reset iterator"
                    "\n(a) - Delete alternate nodes"
                    "\n(m) - Merge two lists"
                    "\n(t) - Intersection"
                    "\n(p) - Print list"
                    "\n(l) - Print length"
                    "\n(q) - Quit program"
            );
        }
           else{
                cout<<"Failed to open the input file"<<endl;
                return 0;
            }
           bool loop = true;
           char character;
           while(loop)
           {
               cout<<"\nEnter a command: ";
               cin>> character;
               cout<<"\n";

               switch (character) {
                   case 'i': {
                       list.printList();
                       cout << "\nEnter number: ";
                       int number;
                       cin >> number;
                       cin >> number;
                       cout << endl;
                       ItemType numType(number);
                       list.insertItem(numType);
                       list.printList();
                       break;
                   }
                   case 'd': {
                       list.printList();
                       int value;
                       cout << "\nEnter value to delete: ";
                       cin >> value;
                       cout << endl;
                       ItemType valueType(value);
                       list.deleteItem(valueType);
                       list.printList();
                       break;
                   }
                   case 's': {
                       cout << "\nEnter value to search: ";
                       int searchNumber;
                       cin >> searchNumber;
                       cout << endl;
                       ItemType searchNumberType(searchNumber);

                       int index = list.searchItem(searchNumberType);
                       if (index != -1)

                           cout << "Index " << index << endl;
                       break;

                   }
                   case 'n': {
                       ItemType item = list.GetNextItem();
                       if (list.length() > 0)
                           cout << item.getValue() << endl;
                       break;
                   }

                   case 'r': {
                       list.ResetList();
                       cout << "Iterator reset." << endl;
                       list.printList();
                       break;
                   }

                   case 'a': {

                   }

                   case 'm': {

                   }

                   case 't': {

                   }

                   case 'p': {
                       list.printList();
                       break;
                   }

                   case 'l': {

                   }

                   case 'q': {
                       cout << "Quitting program..." << endl;
                       loop = false;
                       break;
                   }
                   default: {
                       cout << "Invalid command, try again!" << endl;
                       break;
                   }
               }
           }
            return 0;
        }

