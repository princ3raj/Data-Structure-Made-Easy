//
//  main.cpp
//  DisplayLinkedListFromEnd
//
//  Created by princeraj on 28/04/21.
//



/*
 
 
 Problem-28 How will you display a Linked List from the end?
 Solution: Traverse recursively till the end of the linked list. While coming back, start printing the
 elements.
 that's why this time, I put cout statement after the function call
 
 
 Time Complexity: O(n). Space Complexity: O(n)→ for Stack
 
 */

/*
 Problem-29 Check whether the given Linked List length is even or odd?
 
 method:1- Traverse Completely to the end and then return the count of node as length
 
 method:2- Use a 2x pointer. Take a pointer that moves at 2x [two nodes at a time]. At the end, if
 the length is even, then the pointer will be NULL; otherwise it will point to the last node.
 
 Time Complexity: O(⌊n/2⌋) ≈ O(n). Space Complexity: O(1).
 
 */


/*
 
 
 Problem-30 If the head of a Linked List is pointing to kth element, then how will you get the
 elements before kth element?
 Solution: Use Memory Efficient Linked Lists [XOR Linked Lists].
 
 */

#include <iostream>
using  namespace::std;



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


void RecursiveDisplay(struct Node *s){
    
    if (s==NULL)
    {
        return;
    }
  
    RecursiveDisplay(s->next);
    cout<<s->data<<" ";
}



int EvenOrOddLinkedListLength(Node *p){
    

    while(p && p->next){
        p=p->next->next;
    }
       
    if(p)
        return 0;
    return 1;
}


int main() {
    
    int arr[]={1,2,3,4,5,6};
    
    
    CreateLinkedList(arr, 6);
    RecursiveDisplay(first);
    cout<<endl;
    
    
    int EvenOrOdd=EvenOrOddLinkedListLength(first);
    
    if(EvenOrOdd)
        cout<<"Even"<<endl;
    else
        cout<<"Odd"<<endl;
   
}
