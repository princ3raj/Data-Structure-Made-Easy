//
//  main.cpp
//  ReverseStackElementsUsingOnlyPushAndPopOperation
//
//  Created by princeraj on 11/06/21.
//

/*
 
 this code is taken from the book
 
 Problem-11  Given a stack, how to reverse the elements of the stack using only stack
 operations (push & pop)?
 Solution: Algorithm:
 • First pop all the elements of the stack till it becomes empty.
 • For each upward step in recursion, insert the element at the bottom of the stack.
 Time Complexity: O(n2). Space Complexity: O(n), for recursive stack.
 */

/*
 
 Problem-12  Show how to implement one queue efficiently using two stacks. Analyze the
 running time of the queue operations. Solution: Refer Queues chapter.
 Problem-13  Show how to implement one stack efficiently using two queues. Analyze the running time of the stack operations.
 Solution: Refer Queues chapter.
 */

#include <iostream>
#include <stack>
using namespace std;

stack<int> Stack;



void insertAtBottom(int num){
    
    int temp;
    if(Stack.empty()){
        Stack.push(num);
        return;
    }

    temp=Stack.top();
    Stack.pop();
    insertAtBottom(num);
    Stack.push(temp);
    

    
    
}




void reverse_stack(){
    int data;
    if(Stack.empty())
        return;
    
  
    data=Stack.top();
    Stack.pop();
    reverse_stack();
    insertAtBottom(data);
    
  
    

}






int main() {
    
    Stack.push(5);
    Stack.push(4);
    Stack.push(3);
    Stack.push(2);
    Stack.push(1);
    
    
  
    
    reverse_stack();
    
    
    while(!Stack.empty()){
        cout<<Stack.top();
        Stack.pop();
    }
    
    cout<<endl;
    
    
    
}
