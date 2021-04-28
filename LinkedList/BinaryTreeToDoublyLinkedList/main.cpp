//
//  main.cpp
//  BinaryTreeToDoublyLinkedList
//
//  Created by princeraj on 28/04/21.
//



/*
 
 Problem-33 Given a binary tree convert it to doubly linked list.
 Solution: Refer Trees chapter.
 will solve later when i will have an idea about traversing in a tree
 */

/*
 
 Problem-34 How do we sort the Linked Lists?
 Solution: Refer Sorting chapter.
 
 However, I have done this question using insertion sort and merge sort(which is used for 2 linked list not one)
 when i'll be doing the revision the next time, i'll check again and sort it out
 
 
 */



/*
 Problem-35 Split a Circular Linked List into two equal parts. If the number of nodes in the
 list are odd then make first list one node extra than second list.
 solution:- Just traverse and find the loop and have a counter variable counting till we reach the loop
 it will give you length of the linked list
 then again traverse the list from start to length/2 and length/2+1 to end of loop-1.
 
 it will give you two equal parts.
 
 same solution in formal sentence:
 Algorithm:
 • Store the mid and last pointers of the circular linked list using Floyd cycle finding
 algorithm.
 • Make the second half circular.
 • Make the first half circular.
 • Set head pointers of the two linked lists
 
 
 Remember two make those list circular as well
 
 Time Complexity: O(n). Space Complexity: O(1).
 */



/*

 Problem-36 If we want to concatenate two linked lists which of the following gives O(1)
 complexity?
 1) Singly linked lists
 2) Doubly linked lists
 3) Circular doubly linked lists
 Solution: Circular Doubly Linked Lists. This is because for singly and doubly linked lists, we
 need to traverse the first list till the end and append the second list. But in the case of circular
 doubly linked lists we don’t have to traverse the lists.
 
 
 */


#include <iostream>
using  namespace::std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
