//
//  main.cpp
//  ReverseLinkedListInPairs
//
//  Created by princeraj on 28/04/21.
//

/*
 
 Problem-32 Reverse the linked list in pairs. If you have a linked list that holds 1 → 2 → 3
 → 4 → X, then after the function has been called the linked list would hold 2 → 1 → 4 →
 3 → X.
 
 solution:- First write a Recursive function to Display the linked list in normal order and
 then using trial and error you will be able to write out that function for reverse in pairs
 That's my approach of solving this question
 
 It can also be solved using Iterative approach , which will be very easy to write as
 you have a very clear picture of what's happening.
 
 In Recursion, Sometimes it's hard to think beforehand without Stack tracing (for me explicitly)
 
 
 Time Complexity: O(n). Space Complexity: O(1).
 */





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


//
void ReverseRecursiveDisplayInPairs(struct Node *s){
   
    if (s==NULL)
    {
        return;
    }
    
    
   // being able to write this condition after some trial and error
    if(s->next!=NULL){
        cout<<s->next->data<<" ";
    }
    
    cout<<s->data<<" ";
    
    
    // being able to write this condition after some trial and error
    //and I m passing next to next bcz once one pair is completed, i should target for next pair always
    if(s->next!=NULL){
        ReverseRecursiveDisplayInPairs(s->next->next);
    }

   
}

int main() {
   
    
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12};


    CreateLinkedList(arr, 12);
    
    ReverseRecursiveDisplayInPairs(first);
    cout<<endl;
}
