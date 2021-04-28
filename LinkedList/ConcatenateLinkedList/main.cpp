//
//  main.cpp
//  ConcatenateLinkedList
//
//  Created by princeraj on 23/04/21.
//


/*
 
 For concatenation of two linked list I created two linked list , one with a last pointer
 and then using that last pointer, I made a connection bewteen first and second linked list
 */

/*
 
 for merging two two sorted linked list, I took two pointers third and last.
 first i am checking which linked list first element is big and i'll make sure that whichever linked list first element is large will become the first Linked list as this program is written according to that.
 
 and then using the last pointer, I am connecting it with the next possible smallest element by look up on both linked list
 
 
 Note:- suppose if linked list 2 is having its first element smaller than the first one then we'll have to make the 2nd linked list, our first linked list.
 
This program is using 4 pointers third and last fourth and second
 there is one more first pointer, which we are not moving anywhere so it doesn't get counted
 
 
 */


/*
 
 Problem-31 Given two sorted Linked Lists, how to merge them into the third list in sorted
 order?
 
 solution is done here in the merge function
 
 There is a recursive solution for this question which i didn't code or say i don't know.
 but i'll try it out when i see it the next time
 
 In Both Solutions Complexity will be
 Time Complexity: O(n + m), where n and m are lengths of two lists.
 */

#include <iostream>
using namespace std;


struct Node {
    
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*last=NULL;



void ConcatenateLinkedList(){
    last->next=second;
}


void FirstLinkedList(int arr_1[],int n){
    
    Node *p=NULL;
    first=new Node;
    first->data=arr_1[0];
    first->next=NULL;
    p=first;
    
    for(int i=1;i<n;i++){
        
        Node *q=new Node;
        q->data=arr_1[i];
        q->next=NULL;
        p->next=q;
        p=p->next;
    }
    last=p;

}



void SecondLinkedList(int arr_2[], int n){
    Node *p=NULL;
    second=new Node;
    second->data=arr_2[0];
    second->next=NULL;
    p=second;
    
    for(int i=1;i<n;i++){
        
        Node *q=new Node;
        q->data=arr_2[i];
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


void MergeLinkedList(){
    
    Node *third, *last, *fourth;
    fourth=second;

        if(first->data<fourth->data){

            third=first;
            last=first;
            third=third->next;
            last->next=NULL;

        }else{
            
            third=fourth;
            last=fourth;
            fourth=fourth->next;
            last->next=NULL;
        
        }
    
    
        
    
    while(third!=NULL && fourth!=NULL){
        
        
        
        if(third->data<fourth->data){
            
            
            last->next=third;
            last=third;
            third=third->next;
            
            
        }
        else{
            
            last->next=fourth;
            last=fourth;
            fourth=fourth->next;
         
            
        }
        
        
        if(fourth==NULL){
            
            last->next=third;
            
        }
        
        if(third==NULL){
            
            last->next=fourth;
            
            
        }
        
        
        
        
        
    }
    
        
    }
    
    
    
    
   
        
        
        
        
   
    
    
    
    
    





int main() {
    
    int arr_1[]={-2,-1,2,8,10,15};
    int arr_2[]={4,11,12,19,20,21,22};
    
    
    FirstLinkedList(arr_1, 6);
    SecondLinkedList(arr_2,7);
    
    
    
    
    cout<<"Display first Linked List"<<endl;
    DisplayLinkedList(first);
    
    cout<<"Display second Linked List"<<endl;
    DisplayLinkedList(second);
    
//    cout<<"Concatenate Linked List"<<endl;
//    ConcatenateLinkedList();
//    DisplayLinkedList(first);
    
    MergeLinkedList();
    DisplayLinkedList(first);
    
    
   
    
    
   
}
