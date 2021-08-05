//
//  main.cpp
//  ImplementQueueUsingStack
//
//  Created by princeraj on 05/08/21.
//

/*
 simply, take two stacks and start inserting element in s1, if you are about to delete then, first check s2 is empty, if its not then start popping it out, if its emptied then transfer all elements from s1 to s2 and carry out it further.
 
 From the book:
 Time Complexity: From the algorithm, if the stack S2 is not empty then the complexity is O(1). If the stack S2 is empty, then we need to transfer the elements from SI to S2. But if we carefully observe, the number of transferred elements and the number of popped elements from S2 are equal. Due to this the average complexity of pop operation in this case is O(1).The amortized complexity of pop operation is O(1).
 */

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
