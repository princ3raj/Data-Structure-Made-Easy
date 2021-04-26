//
//  main.cpp
//  CreateDoublyLinkedList
//
//  Created by princeraj on 24/04/21.
//

/*
 
 In some operations, I have used more than required pointers, bcz i was not awared of it before that i could achieve the same task with less pointers.
 
 
 
 
 */

#include <iostream>
using namespace std;



struct Node{
    
    Node *prev;
    int data;
    Node *next;
}*first=NULL;





void CreateDoublyLinkedList(int arr[],int n){
    
    
    Node *p, *q;
    
    first=new Node;
    first->prev=NULL;
    first->data=arr[0];
    first->next=NULL;
 
    p=first;
    
    
    for(int i=1;i<n;i++){
        
        q=new Node;
        p->next=q;
        q->data=arr[i];
        q->prev=p;
        q->next=NULL;
        p=q;
        
    }
    
    
    
}


void DisplayLinkedList(struct Node *p){
    
    Node *q=first;
    int count=0;
    
    
    
    while(p!=NULL){
        count++;
        cout<<p->data<<" ";
        p=p->next;
        
        if(count>=2){
            q=q->next;
        }
        
    }
    
    p=q;
    
    cout<<endl;
    cout<<"Reverse Traversing Order In Doubly Linked List"<<endl;
    
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->prev;
    }
    
    cout<<endl;
    
    
}


void insertBeforeFirstNode(int data){
    
    Node *r=new Node;
    r->data=data;
    r->prev=NULL;
    r->next=first;
    first->prev=r;
    first=r;
    
}



void insertAtAnyGivenIndex(int data, int position){
    if(position==0){
        
        insertBeforeFirstNode(data);
        return;

    }
    
    Node *p=first;
    Node *q=first->next;
    
    for(int i=1;i<position;i++){
        p=p->next;
        q=q->next;
    }
    
    Node *r=new Node;
    r->data=data;
    p->next=r;
    r->prev=p;
    r->next=q;
    q->prev=r;
}


void DeletingFirstNodeInDoublyLinkedList(){
    
    
    Node *p=first;
    first=first->next;
    first->prev=NULL;
    delete p;
    
}



void DeletingNodeAtGivenPosition(int position){
    
    if(position==1){
        DeletingFirstNodeInDoublyLinkedList();
        return;
    }
    
    Node *p,*q,*r;
    p=first;
    q=first->next;
    r=first->next;
    r=r->next;
    
    
    for(int i=2;i<position;i++){
        p=p->next;
        q=q->next;
        r=r->next;
        
    }
    delete q;
    p->next=r;
    r->prev=p;
   

    
}



// That's a good one
void ReversingDoublyLinkedList(){
    
    
    Node *p=first;
    
    while(p){
        
        Node *temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        if(p->prev==NULL){
            first=p;
        }
        p=p->prev;
        
        
        
    }
}


int main() {
    
    int arr[]={9,8,7,6,5};
    
    CreateDoublyLinkedList(arr, 5);
    
    //Displaying Doubly Linked List with both sides
    DisplayLinkedList(first);
    
    insertBeforeFirstNode(1000);
    
    cout<<"Displaying Doubly Linked List"<<endl;
    DisplayLinkedList(first);
    
    insertAtAnyGivenIndex(23,0);
    cout<<"Displaying Doubly Linked List"<<endl;
    DisplayLinkedList(first);
    
    
    DeletingFirstNodeInDoublyLinkedList();
    cout<<"Displaying Doubly Linked List"<<endl;
    DisplayLinkedList(first);
    
    DeletingNodeAtGivenPosition(2);
    cout<<"Displaying Doubly Linked List"<<endl;
    DisplayLinkedList(first);
    
    
    ReversingDoublyLinkedList();
    cout<<"Displaying Reversed Doubly Linked List"<<endl;
    DisplayLinkedList(first);
    
    
}
