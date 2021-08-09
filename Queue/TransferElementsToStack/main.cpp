//
//  main.cpp
//  TransferElementsToStack
//
//  Created by princeraj on 09/08/21.
//


/*
 Problem-5  Given a queue Q containing n elements, transfer these items on to a stack S (initially empty) so that front element of Q appears at the top of the stack and the order of all other items is preserved. Using enqueue and dequeue operations for the queue, and push and pop operations for the stack, outline an efficient O(n) algorithm to accomplish the above task, using only a constant amount of additional storage.
 
 ans: easy one, just dequeue all elements then push to stack and then again pop all elements and enqueue into stack and then pop all elements and push to stack
 */

/*
 Problem-6  A queue is set up in a circular array A[O..n - 1] with front and rear defined as usual. Assume that n – 1 locations in the array are available for storing the elements (with the other element being used to detect full/empty condition). Give a formula for the number of elements in the queue in terms of rear, front, and n
 
 • Rear of the queue is somewhere clockwise from the front.
 • To enqueue an element, we move rear one position clockwise and write the element
 in that position.
 • To dequeue, we simply move front one position clockwise.
 • Queue migrates in a clockwise direction as we enqueue and dequeue.
 • Emptiness and fullness to be checked carefully.
 • Analyze the possible situations (make some drawings to see where front and rear
 are when the queue is empty, and partially and totally filled). We will get this:
 */
#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
