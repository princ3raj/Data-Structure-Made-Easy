//
//  main.cpp
//  StackGetMinimumImpl.
//
//  Created by princeraj on 11/06/21.
//

/*
 
 How to design a stack such that GetMinimum( ) should be O(1)?
 */



#include <iostream>
#include <stack>
using namespace std;

stack<int> main_stack;
stack<int> min_stack;




int getMinimum(){
    
    if(!min_stack.empty()){
        return min_stack.top();
    }
    
    return NULL;
}

void push_user(int num)
{
    if(min_stack.empty()){
        min_stack.push(num);
    }else if(num<min_stack.top()){
        min_stack.push(num);
    }
    
    main_stack.push(num);
        
     
}

    
   



void pop_user()
{
    if(main_stack.top()==min_stack.top()){
        min_stack.pop();
    }
    main_stack.pop();
   
}


int main() {
    
    push_user(2);
    push_user(6);
    push_user(4);
    push_user(1);
    push_user(5);
    
    pop_user();
    pop_user();
    pop_user();
    pop_user();
    pop_user();
    
    cout<<getMinimum()<<endl;
    
    
    
  
}
