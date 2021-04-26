//
//  main.cpp
//  FindNthNodeFromLastInLinkedList
//
//  Created by princeraj on 26/04/21.
//



/*
 
 Problem-2 Find nth node from the end of a Linked List.
 
 4 method/approach to solve this problem
 
 
 
 Method-1:- Brute Force Approach
 Explanation:-
 Start with the first node and count the number of nodes present
 after that node. If the number of nodes is < n – 1 then return saying “fewer number of nodes in the
 list”. If the number of nodes is > n – 1 then go to next node. Continue this until the numbers of
 nodes after current node are n – 1 or say becomes both equal.
 
it will work as like when you see nth element from last means, there will n-1 element from the nth position if nth becomes the 1st element, so we are actually doing this.
 approaching towards until we get n-1 elements from the nth position which we are changing in every iteration after counting.
 
 
 
 Time Complexity: O(n2), for scanning the remaining list (from current node) for each node.
 Space Complexity: O(1).
 
 
 */

/*
 
 Method:2 using Hash Table
 
 means, key is the position of the node in the list and value is the address of that node.
 Position in List Address of Node
 1 Address of 5 node
 2 Address of 1 node
 3 Address of 17 node
 4 Address of 4 node
 
 By the time we traverse the complete list (for creating the hash table), we can find the list length.
 Let us say the list length is M. To find nth from the end of linked list, we can convert this to M- n
 + 1th from the beginning. Since we already know the length of the list, it is just a matter of
 returning M- n + 1th key value from the hash table.
 
 
 Time Complexity: Time for creating the hash table, T(m) = O(m).
 Space Complexity: Since we need to create a hash table of size m, O(m).
 */


/*
 Method :3 Without using hashtable
 
 first traverse the linked list and find the length, once you get the length.
 minus nth from it and traverse, whatever the value comes.
 
 length of node:5
 nth s :3
 
 value= 5-3=2;
 traverse it for 2 times and you will reach the nth element from last
 */


/*
 
 Method :4 Using Two Pointers
 first make n moves with pointer p and then start the q pointer until you reach the pointer which next value is NULL and print the result.
 */

#include <iostream>
using namespace std;


struct Node{
    int data;
    Node *next;
}*first=NULL;



void CreateLinkedList(int arr[], int n){
    
    Node *p=NULL;
    Node *q=NULL;
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


void DisplayLinkedList(){
    
    
    Node *p=first;
    
    while(p){
        
        cout<<p->data<<" ";
        p=p->next;
    }
    
    cout<<endl;
}


//Method:1 Brute Force Approach
void FindNthNode(int n){
    
    n=n-1;
    Node *p=first;
    Node *q=first->next;
    int count=0;
    
    while(p){
        
        while(q){
            
            count++;
            q=q->next;
            
            
            
        }
        
        if(count<n){
            cout<<"fewer number of nodes"<<endl;
            break;
        }
        
        if(count==n){
            cout<<p->data<<" is the nth Node from last"<<endl;
            break;
        }
        count=0;
        p=p->next;
        q=p->next;
    }
    
}


//Method: 3
void FindNthNodeUsingSimpleApproach(int n){
    
    Node *p=first;
    int count=1;
    
    while(p){
        count++;
        p=p->next;
    }
    
    if(count<n){
        cout<<"fewer number of nodes"<<endl;
        return;
        
    }
    
    
    p=first;
    
    for(int i=1;i<count-n;i++){
        p=p->next;
    }
    
    cout<<p->data<<" is the nth node from Last"<<endl;
    
    
    
}



//Method:4
void FindNthNodeUsingSingleScan(int n){
    
    
    Node *p=first;
    Node *q=first;
    
   int count=0;
    int flag=0;
    
    while(p->next!=NULL){
        
        if(flag==0){
            count++;
        }
        
     
        p=p->next;
        if(count==n){
            q=q->next;
            flag=1;
            
        }
    }
    
    if(q==first){
        
        cout<<"fewer number of nodes"<<endl;
    }else{
        cout<<q->data<<" is the nth node from last"<<endl;
    }
    

}








int main() {
    
    
    int arr[]={1,2,3};
    
    CreateLinkedList(arr, 3);
    DisplayLinkedList();
    
    FindNthNode(1);
    
    FindNthNodeUsingSimpleApproach(1);
    
    
    FindNthNodeUsingSingleScan(1);
    
 
}
