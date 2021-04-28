//
//  main.cpp
//  FindMiddleInLinkedList
//
//  Created by princeraj on 28/04/21.
//

/*
 
 Problem-24 How will you find the middle of the linked list?
 
 Solution: Brute-Force Approach: For each of the node, count how many nodes are there in the
 list, and see whether it is the middle node of the list.
 
 because from the middle there always be n/2 elements, if there is n/2 elements then it's a middle
 
 Time Complexity: O(n2). Space Complexity: O(1).
 
 
 */


/*
 
 Problem-25 Can we improve the complexity of Problem-24?
 Solution: Yes.
 
 * Traverse the list and find the length and then again traverse length/2
 it will get you to the middle
 
 Time Complexity: Time for finding the length of the list + Time for locating middle node = O(n) +
 O(n) ≈ O(n).
 Space Complexity: O(1).
 
 */




/*
 
 Problem-26 Can we use the hash table for solving Problem-24?
 Solution: Yes. The reasoning is the same as that of Problem-3.
 Time Complexity: Time for creating the hash table. Therefore, T(n) = O(n).
 Space Complexity: O(n). Since we need to create a hash table of size n.
 
 we can also use array/vector
 
 just store the addresses and then go to (n/2-1)th index
 
 */


/*
 
 
 Problem-27 Can we solve Problem-24 just in one scan?
 Solution: Efficient Approach: Use two pointers. Move one pointer at twice the speed of the
 second. When the first pointer reaches the end of the list, the second pointer will be pointing to
 the middle node.
 Note: If the list has an even number of nodes, the middle node will be of ⌊n/2⌋.
 
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


void RecursiveDisplay(struct Node *s){
    
    if (s==NULL)
    {
        return;
    }
  
    cout<<s->data<<" ";
    
    return RecursiveDisplay(s->next);
}



//My Approach
//Efficient Approach in just one scan
void FindMiddleUsingTwoPointers(Node *p,Node *q){

    //keep looping until we reach the tail (next will be NULL for the last Node)
    while(p->next!=NULL){
        
        p=p->next;
        
        if(p->next!=NULL){
            p=p->next;
            
        }
        q=q->next;
    }
    cout<<"This is the middle Node "<<q->data<<endl;
}




//Book's Approach
//Efficient Approach in just one scan
void FindMiddle(Node *p,Node *q){
    
    int i=0;
    
    
    //keep looping until we reach the tail (next will be NULL for the last Node)
    while(p->next!=NULL){
        
        
        if(i==0){
            p=p->next; //increment only the 1st poniter
            i=1;
        }else if (i==1){
            
            p=p->next; // increment both pointers
            q=q->next;
            i=0;
        }

    }
    cout<<"This is the middle Node "<<q->data<<endl;
}







int main() {
    
    
    int arr[]={1,2,3,4,5,6};
    
    
    CreateLinkedList(arr, 6);
    RecursiveDisplay(first);
    cout<<endl;
    
    FindMiddleUsingTwoPointers(first->next,first);
    
}
