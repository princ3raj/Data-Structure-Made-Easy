//
//  main.cpp
//  ReplaceWithNearestGreaterElement
//
//  Created by princeraj on 02/08/21.
//

/*
 Geeksforgeeks Solution
 Given an array of integers, replace every element with the next greatest element (greatest element on the right side) in the array. Since there is no element next to the last element, replace it with -1. For example, if the array is {16, 17, 4, 3, 5, 2}, then it should be modified to {17, 5, 5, 5, 2, -1}.
 
 The question is very similar to this post and solutions are also similar.
 A naive method is to run two loops. The outer loop will one by one pick array elements from left to right. The inner loop will find the greatest element present after the picked element. Finally the outer loop will replace the picked element with the greatest element found by inner loop. The time complexity of this method will be O(n*n).
 A tricky method is to replace all elements using one traversal of the array. The idea is to start from the rightmost element, move to the left side one by one, and keep track of the maximum element. Replace every element with the maximum element.
 */


/*
 this one is focused on nearest greater not just greater
 Given an array of elements, replace every element with nearest greater element
 on the right of that element.
 Solution: The approach is pretty much similar to Problem-22. Create a stack and push the first element. For the rest of the elements, mark the current element as nextNearestGreater. If stack is not empty, then pop an element from stack and compare it with nextNearestGreater. If nextNearestGreater is greater than the popped element, then nextNearestGreater is the next greater element for the popped element. Keep popping from the stack while the popped element is smaller than nextNearestGreater. nextNearestGreater becomes the next greater element for all such popped elements. If nextNearestGreater is smaller than the popped element, then push the popped element back.
 Time Complexity: O(n). Space Complexity: O(n).
 */

#include <iostream>
#include <stack>



int main() {
}
