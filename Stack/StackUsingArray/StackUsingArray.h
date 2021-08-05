//
//  StackUsingArray.h
//  Stack
//
//  Created by princeraj on 05/05/21.
//

#ifndef StackUsingArray_h
#define StackUsingArray_h

#include <iostream>
using namespace std;




class Node{
public:
    int size; // size of the stack defined by this
    int top; // at initial it will point to -1
    int *s ;// integer type pointer which will point to an integer array
    
  
    
};

class Stack{
    
    
    
private:
    Node stack;
 
    
public:
 
    Stack(long size){
        
        stack.size=size;
        stack.top=-1;
        stack.s=new int[size];
    }
    

    
    void push(int data){
        
        if(stack.top==stack.size-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        stack.top++;
        stack.s[stack.top]=data;
    }
    
    
    
    void pop(){
        
        if(stack.top==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        
        stack.s[stack.top]=NULL;
        stack.top--;
        
    }
    
    
    
    void peek(int position){
        
        int index=stack.top-position+1;
        
        if(index > stack.top || index < 0){
            
            cout<<"Invalid location"<<endl;
            return;
            
        }
        cout<<stack.s[index]<<endl;
        
    }
    
    
    
    
    void search(int element){
        
        int index=stack.top;
        
        
        while(index>=0 && index < stack.size-1){
            
            if(stack.s[index]==element){
                cout<<element<<" found at index: "<<index<<endl;
                return;
            }
            
            index--;
        }
        
        cout<<"Element doesn't exist"<<endl;
    }
    
    
    
    
    void show(){
        int i=stack.top;
        
        while(i!=-1){
            cout<<stack.s[i]<<" ";
            i--;
        }
        cout<<endl;
    }
    
    
    int Top(){
        
        
        if(stack.top==-1){
            return 0;
        }
        return stack.s[stack.top];
        
    }
    
    int isEmpty(){
        
        if(stack.top==-1){
            return 1;
            
        }
        return 0;
        
    }
    
    int Size(){
        
        return stack.top+1;
    }
    
    
    
    int isFull(){
        
        if(stack.top==stack.size-1){
            return 1;
            
        }
        
        return 0;
        
    }
    

};








#endif /* StackUsingArray_h */
