//
//  main.cpp
//  CircularDoublyLinkedList
//
//  Created by princeraj on 24/04/21.
//

#include <iostream>
using namespace std;


struct Node {
    
    Node *prev;
    int data;
    Node *next;
}*first=NULL;



void CreateCircularDoublyLinkedList(int arr[],int n){
    
    Node *p,*q;
    first=new Node;
    first->data=arr[0];
    first->prev=NULL;
    first->next=NULL;
    p=first;
    q=NULL;
    
    
    for(int i=1;i<n;i++){
        
        q=new Node;
        q->prev=p;
        p->next=q;
        q->data=arr[i];
        q->next=NULL;
        p=q;
        
        
    }
    
    p->next=first;
    first->prev=p;

}


void DisplayLinkedList(struct Node *p){
    int count=0;
    do{
        count++;
        cout<<p->data<<" ";
        p=p->next;
        
        if(p==first){
            break;
        }
        
    }while(p!=NULL);
    
    cout<<endl;
    
    cout<<"No. of nodes in a Circular Doubly Linked List is: "<<count<<endl;
    
    
    do{
        count++;
        cout<<p->data<<" ";
        p=p->prev;
        
        if(p==first){
            break;
        }
        
    }while(p!=NULL);
    
    cout<<endl;
    


}


void InsertAtMidInCircularDoublyLinkedList(int data, int position){
    
    //I have commented the r pointer to use less pointers for this operation, However
    //you can uncomment the code and it'll work as this one
    
    Node *p;
    p=first;
//    r=first->next;
    
    for(int i=1;i<position;i++){
        p=p->next;
//        r=r->next;
        
    }
    
//    Node *q=new Node;
//    q->data=data;
//    q->prev=p;
//    p->next=q;
//    r->prev=q;
//    q->next=r;
    
    
    Node *q=new Node;
    q->data=data;
    q->next=p->next;
    p->next=q;
    q->prev=p;
    p=p->next;
    p=p->next;
    p->prev=q;

    
}


void insertAtEndCircularDoublyLinkedList(int data){
    Node *p=first;
    
    while(p->next!=first){

        p=p->next;
    }
    
    Node *q=new Node;
    q->data=data;
    q->prev=p;
    p->next=q;
    q->next=first;
    first->prev=q;

}










int main() {
    
    int arr[]={1,2,3,4,5,6,7,8,10,11};
    CreateCircularDoublyLinkedList(arr,10);
    DisplayLinkedList(first);
    
    
    insertAtEndCircularDoublyLinkedList(12);
    DisplayLinkedList(first);
    
    InsertAtMidInCircularDoublyLinkedList(1000, 3);
    DisplayLinkedList(first);
    
}
