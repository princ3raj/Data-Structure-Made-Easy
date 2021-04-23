//
//  main.cpp
//  CheckLInkedListSortedOrNot
//
//  Created by princeraj on 21/04/21.
//

#include <iostream>
using namespace std;


//Globally declared Nodes and first pointer
struct Node{
    
    
    int data;
    struct Node *next;
    
}*first=NULL;




int FindLinkedListSortedOrNot(Node *p){
    Node *q=p;
    p=p->next;

    while(p!=NULL){
        if(p->data<q->data){
            return 0;
        }
        q=p;
        p=p->next;
    }
    
    return 1;
    
}


int RecursiveLinkedListSortOrNot(Node *p,Node *q){
  
    if(p==NULL){
        return 1;
    }
    
    return (p->data<q->data?0:RecursiveLinkedListSortOrNot(p->next,p));
}







void createLinkedList(int arr[], int n){
    
    Node *p,*q;
    
    first=new Node;
    first->data=arr[0];
    first->next=NULL;
    
    p=first;
  
    
    for(int i=1;i<n;i++){
        
        q=new Node;
        q->data=arr[i];
        q->next=NULL;
        p->next=q;
        p=q;
    }
    
    
}


void DisplayLinkedList(struct Node *p){
    
    
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
}





int main() {
    
    
    int arr[]={-1,999,4,12,32,34};
    
    createLinkedList(arr,6);
    DisplayLinkedList(first);
    
    
    cout<<endl;
    
    
    //returns 1 if sorted else 0;
    cout<<FindLinkedListSortedOrNot(first)<<endl;
    
    cout<<"Recursive"<<endl;
    cout<<RecursiveLinkedListSortOrNot(first->next,first)<<endl;;
    
}
