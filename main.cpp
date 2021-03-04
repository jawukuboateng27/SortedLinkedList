#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <cstdlib>

#include "SortedLinkedList.cpp"
#include "ItemType.cpp"
#include "SortedLinkedList.h"
#include "ItemType.h"
#include "ListNode.h"

using namespace std;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;

int main(int argc, char *argv[]) {

    // Init List Object
    SortedLinkedList list;

    // Read file
    ifstream readFile(argv[1]);
    string input = "";
    while(getline(readFile,input)) {
        istringstream iss(input);
        ItemType item;
        int num;
        // Add to list
        while (iss >> num) {
            item.initialize(num);
            list.insertItem(item);
        }
    }
/*
    // Error Handling: Incorrect input file
    else{
        cout<<"Failed to open the input file"<<endl;
        return 0;
    }
    */

    // while loop
    while (true) {
        cout<<(
            "(i) - Insert value"
            "\n(d) - Delete value"
            "\n(s) - Search value"
            "\n(n) - Print next iterator value"
            "\n(r) - Reset iterator"
            "\n(a) - Delete alternate nodes"
            "\n(m) - Merge two lists"
            "\n(t) - Intersection"
            "\n(p) - Print list"
            "\n(l) - Print length"
            "\n(q) - Quit program"
        );

        // User Input: Command
        cout << "Enter a command:  ";
        getline(cin, input);

        // Command "i" - Insert value
        if (input.compare("i") == 0) {
            // Print current list
            list.printList();
            ItemType item;
            // User Input: number
            cout << "Enter a number:  ";
            getline(cin, input);
            // Add User number to list
            item.initialize(stoi(input));
            list.insertItem(item);
            // Print updated list
            list.printList();
        }

        // Command "d" - Delete value
        else if  (input.compare("d") == 0 ) {
            // Print current list
            list.printList();
            ItemType item;
            // User Input: number
            cout << "Enter a number:  ";
            getline(cin, input);
            // Delete User number from list
            item.initialize(stoi(input));
            list.deleteItem(item);
            // Print updated list
            list.printList();
        }

        // Command "s" - Search value
        else if (input.compare("s") == 0 ) {
            ItemType item;
            // User Input: number
            cout << "Enter a number:  "; 
            getline(cin, input);
            // Search User number
            item.initialize(stoi(input));
            int index = list.searchItem(item);
            cout << "Index " << index << endl;
        }
        
        // Command "n" - Print next iterator value
        else if (input.compare("n") == 0) { //to go to next
            // Non-empty list
            if (list.length() != 0) {
                cout<< list.GetNextItem().getValue() << endl;
            }
            // Empty List
            else {
                cout << "List is empty" << endl;
            }
        }

        // Command "r" - Reset iterator
        else if (input.compare("r") == 0 ) {
            // Reset list
            list.ResetList();
        }

        // Command "a" - Delete alternate nodes
        else if (input.compare("a") == 0 ) {
            // COMPLETE
        }

        // Command "m" - Merge two lists
        else if (input.compare("m") == 0 ) {
            // COMPLETE
        }

        // Command "t" - Intersection
        else if (input.compare("t") == 0 ) {
            // COMPLETE
        }

        // Command "p" - Print list
        else if (input.compare("p") == 0 ) {
            // Print List
            list.printList();
        }

        // Command "l" - Print length
        else if (input.compare("l") == 0 ){
            // Print List Length
            cout << "List Length is " << list.length() << endl;
        }

        // Command "q" - Quit program
        else if (input.compare("q") == 0 ) {
            // Exit Main
            return 0;
        }

        // Error Handling: Invalid Command
        else {
            cout << "Invalid command, try again!" << endl;
        }
  } //while 
} //main