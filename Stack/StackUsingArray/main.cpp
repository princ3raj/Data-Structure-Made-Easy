//
//  main.cpp
//  StackUsingArray
//
//  Created by princeraj on 05/05/21.
//

#include <iostream>
#include "StackUsingArray.h"
using namespace std;

int main() {
    
    Stack stack(10);
    
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);

    
    
    stack.show();
    
    stack.search(23);
    
    stack.peek(-1);
    
    cout<<stack.Size()<<endl;
    
    cout<<stack.isEmpty()<<endl;
    
    cout<<stack.isFull()<<endl;
    
    cout<<stack.Top()<<endl;
}
