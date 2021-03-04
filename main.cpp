#include <iostream>
#include <fstream>
#include <string>
#include "SortedLinkedList.h"
#include "ItemType.h"

using namespace std;

int main(int argc, char * argv[]) {
    SortedLinkedList list; 
    
    ItemType item;
    int input;
    fstream fs;

    fs.open(argv[1], fstream::in); // reads input file

    if (fs.is_open()) {
    	fs >> input;
    	while (!fs.eof()) {
    	    item.initialize(input);
    	    list.insertItem(item);
    	    fs >> input;
    	}

    	cout << "Commands:" << endl;
    	cout << "\n(i) - Insert value" << endl;
    	cout << "\n(d) - Delete value" << endl;
    	cout << "\n(s) - Search value" << endl;
    	cout << "\n(n) - Print next iterator value" << endl;
    	cout << "\n(r) - Reset iterator" << endl;
    	cout << "\n(p) - Print list" << endl;
    	cout << "\n(l) - Print length" << endl;
    	cout << "\n(a) - Delete Altnate Node" << endl;
    	cout << "\n(q) - Quit program" << endl;
    }

    else {
    	cout << "Failed to open the input file" << endl;
    	return 0;
    }

    bool loop = true;
    char character; // character input when entering a command

    while (loop) {
    	cout << "\nEnter a command: ";
    	cin >> character;
    	cout << "\n";

    	switch (character) {
    	case 'i': { // insert command that inserts a node in the linked list
    	    list.printList();
    	    cout << "\nEnter number: ";
    	    int number;
    	    cin >> number;
    	    cout << endl;
    	    ItemType numType(number);
    	    list.insertItem(numType);
    	    list.printList();
    	    break;
    	}
    	case 'd': { // delete command that deletes a node in the linked list
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
    	case 's': { // search command that searches for a node in the linked list
    	    cout << "Enter value to search: ";
    	    int searchNum;
    	    cin >> searchNum;
    	    cout << endl;
    	    ItemType searchNumType(searchNum);

	    int index = list.searchItem(searchNumType);

	    if(index != -1)
		cout << "Index " << index << endl;
    	    break;
    	}
    	case 'n': { // next command that gets the next node in the linked list
	    ItemType item = list.GetNextItem();

	    if(list.length() > 0)
		cout << item.getValue() << endl;
    	    break;
    	}
    	case 'r': { // reset command that restarts the linked list back to the first position and element
    	    list.ResetList();
    	    cout << "Iterator reset." << endl;
    	    break;
    	}
    	case 'p': { // print command that prints the linked list
    	    list.printList();
    	    break;
    	}
    	case 'l': { // length command that returns the length of the linked list
    	    cout << "List Length is " << list.length() << endl;
    	    break;
    	}
    	case 'a': { // Delete alt node
	  
	    
    	    list.printList();

    	    cout << endl;

    	    list.DeleteAlternateNodes(item);
	    
    	    cout << "After" << endl;

    	    cout << endl;

    	    list.printList();
    	    break;
    	}
    	case 'q': { // quit command that stops the while loop and exits the program
    	    cout << "Quitting program..." << endl;
    	    loop = false;
    	    break;
    	}
    	default: { // this will print when the command is invalid
    	    cout << "Invalid command, try again!" << endl;
    	    break;
    	}
    	}

    }
}
