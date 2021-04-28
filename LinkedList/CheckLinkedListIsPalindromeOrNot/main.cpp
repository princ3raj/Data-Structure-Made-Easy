//
//  main.cpp
//  CheckLinkedListIsPalindromeOrNot
//
//  Created by princeraj on 28/04/21.
//



/*
 
 

 
 void CheckPalindromeOrNot(Node *p,Node *q){

     int count=1;
     Node *r=NULL;
     if(first->next!=NULL){
      r=first->next;
     }else{
         cout<<"it's a palindrome"<<endl;
         return;
     }

     while(q->next!=NULL){
         q=q->next;
         count++;
     }


     //Now q is pointing to the last element
     cout<<count<<endl;

     if(p->data!=q->data){
         cout<<"Not a Palindrome"<<endl;
         return;
     }


     p=first->next->next;

     for(int i=0;i<count/2;i++){

         if(p==NULL){
             break;

         }

         if(r->data==p->data){
             r=r->next;
             p=p->next;
         }else{
             cout<<"Not a Palindrome"<<endl;
             return;
         }


     }

     cout<<"It's a Palindrome"<<endl;





 }
 
 */





/*
 
 Problem-37 How will you check if the linked list is palindrome or not?
  I tried an approach , but it finally failed at this output 1 1 0 0 1 1  , you can see it in the commented code
 
 let's what's the approach mentioned in the book
 
 Solution:
 Algorithm:
 1. Get the middle of the linked list.
 2. Reverse the second half of the linked list.
 3. Compare the first half and second half.
 4. Construct the original linked list by reversing the second half again and
 attaching it back to the first half
 
 Time Complexity: O(n). Space Complexity: O(1).
 
 However, i didn't reverse the linked list literally, instead i used an temp_arr
 
 */

#include <iostream>
using namespace std;


int temp_arr[10]={99999};
static int increment=0;

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
   
    cout<<s->data<<" ";
    
    return RecursiveDisplay(s->next);
}


void ReverseLinkedList(struct Node *s){
    
    if (s==NULL)
    {
        return;
    }
  
    ReverseLinkedList(s->next);
    temp_arr[increment]=s->data;
    increment++;
    
}


void CheckPalindromeOrNot(Node *p, Node *q){
    
    //find the length
    int length=1;
    while(q->next!=NULL){
        q=q->next;
        length++;
        
        
    }
    
//    cout<<length<<endl;
    
    //find the middle
    int middle=length/2;
    
    Node *r=first;
    
    for(int i=0;i<middle;i++){
        r=r->next;
    }
//    cout<<"r data"<<endl;
//    cout<<r->data<<endl;
    
    
//    cout<<"Reverse Linked List"<<endl;
    ReverseLinkedList(r);
    
//    for(int j=0;j<middle;j++){
//
//        cout<<temp_arr[j]<<" ";
//
//    }
    
   
    
    for(int k=0;k<middle;k++){
        if(p->data==temp_arr[k]){
            p=p->next;
        }else{
            cout<<"Not a Palindrome"<<endl;
            return;
        }
    }
    
    cout<<"Palindrome"<<endl;
    

    
}



int main() {
    
    int arr[]={1,2,3,4};
    
    
    CreateLinkedList(arr, 4);
    
    RecursiveDisplay(first);
    cout<<endl;
    
    
    CheckPalindromeOrNot(first, first);
    
    
    
  
    
    
    
}
