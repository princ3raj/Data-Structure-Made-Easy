//
//  main.cpp
//  MaximumSumInSlidingWindow
//
//  Created by princeraj on 05/08/21.
//
/*
 
 Problem-4  Maximum sum in sliding window: Given array A[] with sliding window of size w which is moving from the very left of the array to the very right. Assume that we can only see the w numbers in the window. Each time the sliding window moves rightwards by one position. For example: The array is [1 3 -1 -3 5 3 6 7], and w is 3.
 
 Solution: This problem can be solved with doubly ended queue (which supports insertion and deletion at both ends). Refer Priority Queues chapter for algorithms.
 
 However, my solution is silly and will elevate the space complexity by n.
 But, let me write it out, I'll create (w-1) arrays and then traverse through the first array and start adding element to the both arrays from  indexes (w-2) and (w-1).
 then again traversing through all arrays and picking one element from each and add altogether and store it in any of the array.
 it'll result in O(n) time complexity but increase the space complexity by O(w-1)
 */

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
