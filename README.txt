CSCI 2720 - Assignment 2
Date: March 3rd, 2021

Faisal Hossain fh64801@uga.edu
Jeffrey Awuku-Boateng jka56880@uga.edu

Contribution:




Pseudocode for Intersection:
We created a new SortedLinkedList and ListNode to access the elements of the SortedLinkedList. A while loop was used to iterate through the list being passed in. Inside of the while loop, we used the search method to find the values that were the same. When a duplicate value was found, an ItemType object was created to initialize and insert items into a final list. Loop continues till next item was null. After all of this the final list was returned.

Time Complexity of Intersection:
The while loop in the intersection method runs up to 'n' times and the if statement that utilizes the search  method has complexity 'O(n)'. Due to this our intersection method has a time complexity of O(n^2). Instead of using searchItem, one constructs two incrementors for the two lists. They increment up to n1 and n2 respectively. Utilizing this method, one is able to iterate through the lists simultaneously. Its resulting time complexity is 'O(n)'. Unfortunately, our algorithm did not achieve this efficiency.

Pseudocode for Merge:
For the merge method, a loop was used to iterate through the second list and the search method compared each list item to the original list to find duplicates. After confirming that there were no duplicates being added, a while loop was used to iterate through the list, make a copy of the items and insert that copy into the original list.

Time Complexity of Merge:
The ‘for’ loop in the merge method runs up to 'n' times. Within this ‘for’ loop, the search method is used. Search method has a time complexity of 'O(n)'. This yields to a time complexity of O(n^2). The ‘while’ loop in this method runs up to ‘n’ times. The insert method was also used. Insert runs ‘n’ times inside the ‘while’ loop causing the 2nd section of the merge function to have O(n^2). The overall time complexity for the merge function is 'O(n^2)'. A more efficient method would had been the K-Way merge function, which has the time complexity O(n)log(k). This function achieves this lower complexity and is hence a more efficient method. 

