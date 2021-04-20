//
//  main.cpp
//  SearchingInLinkedList
//
//  Created by princeraj on 20/04/21.
//

/*
 This Module Contain LinearSearch approach and Move to head method and their Recursive Approach for searching in a Linked List
 
 
 
 
 */


int node_number;

#include <iostream>
using namespace std;


//Globally declared Nodes and first pointer
struct Node{
    
    
    int data;
    struct Node *next;
    
}*first=NULL;


void CreateLinkedList(int arr[], int n){

    Node *q,*r;
    first=new Node;
    q=first;
    
    first->data=arr[0];
    first->next=NULL;
    
    for(int i=1;i<n;i++){
        
        r=new Node;
        r->data=arr[i];
        r->next=NULL;
        q->next=r;
        q=q->next;
    
    }
    
}

//it will return a Node type Pointer or NULL
Node* LinearSearchInLinkedList(struct Node *p,int search_number){
    
    
    node_number=1;

    while (p){
        
        if(search_number==p->data)
               return p;
        
        
        node_number++;
        p=p->next;
        
    
}
    
    return NULL;
    
}

Node* RecursiveLinearSearchInLinkedList(Node *p,int search_number){
    
    
    if(p==NULL){
        return NULL;
    }
    
    
    if(search_number==p->data)
        return p;
    
    
    return RecursiveLinearSearchInLinkedList(p->next, search_number);
    
    
    
}


Node* MoveToHeadMethodForSearching(Node *p,int search_number){
    
    
    struct Node *q=NULL;
    
    
    while(p){
        
        
        if(search_number==p->data){
            
            q->next=p->next;
            p->next=first;
            first=p;
            
            
            return p;
            
        }else{
            
            q=p;
            p=p->next;
        }
        
    }
    
    
    
    return NULL;
    
    
    
    
}


    
    
    



int main() {
    
    
 
    
    
    int arr[]={1,2,3,46,1,23,45,11,2,64};
    
    
    CreateLinkedList(arr, 10);
    
    Node* FoundOrNotFound=LinearSearchInLinkedList(first, 23);
    
    if(FoundOrNotFound){
        cout<<"Element Found at this address: "<<FoundOrNotFound<<endl;
        cout<<node_number<<endl;
    }else{
        cout<<"Element Not Found"<<endl;
    }
    
    
    
    cout<<"Recursive Solution for Search in Linked List: "<<endl;
    
    
    cout<<RecursiveLinearSearchInLinkedList(first, 23)<<endl;
    
    
    cout<<"Move to Head Method In Linked List Linear Search:"<<endl;
    
    cout<<MoveToHeadMethodForSearching(first, 23)<<endl;
    
    cout<<"Checking Move to head:"<<endl;
    
    cout<<LinearSearchInLinkedList(first, 23)<<endl;
    cout<<node_number<<endl;
  
    
    
    
    
  
    
    
    
    

    
    
    
 
}
