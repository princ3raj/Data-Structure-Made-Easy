//
//  main.cpp
//  Stack
//
//  Created by princeraj on 28/04/21.
//

#include <iostream>
using namespace std;


struct Stack{
    
    int size;
    int top;
    int *s;

};
//Globally declared
Stack stack;


void push(int data){
    
    
    if(stack.top==stack.size-1){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    
    stack.top++;
    stack.s[stack.top]=data;
    
//    cout<<"pushed: "<<data<<endl;
}


void pop(){
    
    if(stack.top==-1)
    {
        cout<<"stack underflow"<<endl;
        return;
    }
    
    stack.s[stack.top]=NULL;
    stack.top--;
}


void print(){
    
    for(int i=stack.top;i>-1;i--){
        cout<<stack.s[i]<<" ";
    }
    cout<<endl;
    
}

void peek(int position){
    
    
    int index=stack.top-position+1;
    
    if(index<=-1)
    {
        cout<<"No such position exists"<<endl;
        return;
    }
    
    if(index>stack.size-1){
        cout<<"No such position exists"<<endl;
        return;
    }
    
    cout<<"This is the element reside at entered position: "<<stack.s[index]<<endl;
    
    
        
    
    
    
    
    
   
}





int main() {
    

    cout<<"Enter the size of the stack"<<endl;
    cin>>stack.size;
    stack.s=new int[stack.size];
    stack.top=-1;
    

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    
    print();
    
    pop();
    pop();
    
    print();
    
    
    
    
    pop();
    pop();
    pop();
    pop();
    
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    
    peek(1000);
    
    
    
    
    
    
    

}
