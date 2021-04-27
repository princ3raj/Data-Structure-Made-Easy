//
//  main.cpp
//  RemoveDuplicatesInLinkedList
//
//  Created by princeraj on 22/04/21.
//

/*
 Remove Duplicates from a Sorted Linked List
 
 INPUT/OUTPUT
 
 Elements with Dupicates
 1 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 4 4 4 4 5 5 5 6 6 6
 Removing the Duplicates
 1 2 3 4 5 6
 
 
 Problem-16 Reverse a singly linked list.
 Method: 1 Reversing Elements,using Recursion
 6 5 4 3 2 1
 Time Complexity: O(n). Space Complexity: O(n),for recursive stack.
 There is another version of Recursive function of this problem which doesn't uses a for loop.
 
 
 
 Problem-16 Reverse a singly linked list.
 Method:2 Reversing Links
 1 2 3 4 5 6
 Time Complexity: O(n). Space Complexity: O(1).
 
 
 

 */

#include <iostream>
using namespace std;

struct Node{
    
    int data;
    struct Node *next;
}*first=NULL;



void removeDuplicates(Node *p){
    
    Node *q=p->next;

    
    while(q!=NULL){
        
        if(p->data!=q->data){
            
            
            p=q;
            q=q->next;
            
        }else{
            
            p->next=q->next;
            delete q;
            q=p->next;
            
            
            
            
            
        }
        
    }
    
    
   
}



void swap(Node *p, Node *q){
    
    int temp=p->data;
    p->data=q->data;
    q->data=temp;
}


//Method:1 Reversing elements
//Recursive Function to Reverse the linked list
void ReverseLinkedList(Node *p,Node *q, int n){
    if(n==0){
        return;
    }

    for(int i=1;i<n;i++){
        swap(p,q);
        p=p->next;
        q=q->next;
    }
    
    ReverseLinkedList(first,first->next,n-1);
}





//Method:2 Reversing links using sliding pointer p,q and r.
void ReverseLinks(Node *p){
    Node *q, *r;
    q=NULL;
    r=NULL;
    
    while (p!=NULL) {
        
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    
    }
    first=q;
}











void CreateLinkedList(int arr[],int n){
    Node *p,*q;
    first=new Node;
    p=first;
    first->data=arr[0];
    first->next=NULL;
    for(int i=1;i<n;i++){

        q=new Node;
        q->data=arr[i];
        q->next=NULL;
        p->next=q;
        p=p->next;
        
    }

}




void DisplayLinkedList(struct Node *p){

    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}




int main() {
   
    int arr[]={1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,5,5,5,6,6,6};
    CreateLinkedList(arr,26);
    cout<<"Elements with Dupicates"<<endl;
    DisplayLinkedList(first);
    
    
    cout<<"Removing the Duplicates in sorted Linked List"<<endl;
    removeDuplicates(first);
    DisplayLinkedList(first);
    
    
    
    cout<<"Method: 1 Reversing Elements,using Recursion "<<endl;
    ReverseLinkedList(first,first->next,6);
    DisplayLinkedList(first);

    
    cout<<"Method:2 Reversing Links"<<endl;
    ReverseLinks(first);
    DisplayLinkedList(first);

}
