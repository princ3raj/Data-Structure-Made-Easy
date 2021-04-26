//
//  main.cpp
//  StackImplementationUsingLinkedList
//
//  Created by princeraj on 25/04/21.
//

/*
  
 Problem-1 Implement Stack using Linked List.
 

 
 
 
 */

#include <iostream>
using namespace std;


class Node{
    
public:
    int data;
    Node *next;
    
};

class LinkedList{
    
private:
    Node *first;
    Node *last;

public:
    
    //when the constructor called itself, it will create a dummy linked list
    LinkedList(int arr[],int n){
        
        Node *p,*q=NULL;
        first=new Node();
        first->data=arr[0];
        first->next=NULL;
        p=first;
        
        
        for(int i=1;i<n;i++){
            q=new Node();
            q->data=arr[i];
            q->next=NULL;
            p->next=q;
            p=q;
            
        }

    }
    
    void Display(){
        
        Node *p=first;

        while(p){
            cout<<p->data<<" ";
            p=p->next;
        }
        
        cout<<endl;
    }
    
    void push(int data){
        
        
        Node *p=first;
 
        
        while(p->next!=NULL){
            p=p->next;
            
        }
    
        Node *r=new Node();
        r->data=data;
        r->next=NULL;
        p->next=r;
        p=r;
        
        cout<<"Pushed: "<<p->data<<endl;
 
    
    }
    
    
    
    void pop(){
        
        Node *p=first->next;
        Node *q=first;
        
        while (p->next!=NULL) {
            
            
            q=q->next;
            p=p->next;
            
        }
        
        q->next=NULL;
        cout<<"Popped: "<<p->data<<endl;
        
        delete p;
        
        
        
       
       
    }
    
    
    
    
    
};













int main() {
    
    int arr[]={1,2,3,4,5};
    
    LinkedList stack(arr,5);
    stack.Display();
    stack.push(6);
    stack.push(7);
    stack.push(8);
    stack.push(9);
    stack.Display();
    
    
    stack.pop();
    stack.pop();
    stack.pop();
    
    


    stack.Display();
}
