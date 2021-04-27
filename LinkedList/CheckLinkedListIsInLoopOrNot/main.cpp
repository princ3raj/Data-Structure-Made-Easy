//
//  main.cpp
//  CheckLinkedListIsInLoopOrNot
//
//  Created by princeraj on 23/04/21.
//

#include <iostream>
using namespace std;

/*
 Problem-6 Check whether the given linked list is either NULL-terminated or ends in a cycle
 (cyclic).
 
 Yes. Efficient Approach (Memoryless Approach): This problem was solved by
 Floyd. The solution is named the Floyd cycle finding algorithm. It uses two pointers moving at
 different speeds to walk the linked list. Once they enter the loop they are expected to meet, which
 denotes that there is a loop.
 
 example:- race track with different car speeds and there will be a time that one can complete a round
  and saying hello the driver which is still in midway to complete the first round.
 
  it's like meeting at point if track is circular and speeds are different.
 
 Note: slowPtr (tortoise) moves one pointer at a time and fastPtr (hare) moves two pointers at a
 time.
 you can also move it by 4times
 
 Time Complexity: O(n). Space Complexity: O(1).
 
 
 Problem-10 are given a pointer to the first element of a linked list L. There are two
 possibilities for L: it either ends (snake) or its last element points back to one of the
 earlier elements in the list (snail). Give an algorithm that tests whether a given list L is a
 snake or a snail.
 Solution: It is the same as above
 
 
 
 Problem-11 Check whether the given linked list is NULL-terminated or not. If there is a
 cycle find the start node of the loop.
 
 Solution: The solution is an extension to the solution in Problem-9. After finding the loop in the
 linked list, we initialize the slowPtr to the head of the linked list. From that point onwards both
 slowPtr and fastPtr move only one node at a time. The point at which they meet is the start of the
 loop. Generally we use this method for removing the loops.
 
 Time Complexity: O(n). Space Complexity: O(1).
 
 
 Problem-13 In the Floyd cycle finding algorithm, does it work if we use steps 2 and 3
 instead of 1 and 2?
 Solution: Yes, but the complexity might be high. Trace out an example
 
 
 Problem-14 Check whether the given linked list is NULL-terminated. If there is a cycle, find
 the length of the loop.
 Solution: Just take a count and increment it until you find, that a loop exits and then minus 1 from count
 
 */


struct Node{
    
    
    int data;
    struct Node *next;
}*first=NULL;





void CreateLinkedList(int arr[],int n){
    
    
    Node *q=NULL;
    first=new Node;
    first->data=arr[0];
    first->next=NULL;
    Node *p=first;
    
    Node *r=NULL;
    
    
    int count=1;
    
    for(int i=1;i<n;i++)

    {
        count++;
        q=new Node;
        q->data=arr[i];
        q->next=NULL;
        p->next=q;
        p=p->next;
        
        if(count==3){
            r=p;
        }
        
    }
    
    p->next=r;

    
}

void DisplayLinkedList(struct Node *p){

    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}


//
//int CheckLinkedListIsInLoopOrNot(Node *p,Node *q){
//
//    int count=1;
//
//
//    while(p!=q){
//        count++;
//        q=q->next;
//        q=q->next;
//        p=p->next;
//
//        if(p==NULL || q==NULL){
//            return 0;
//        }
//
//
//    }
//
//    cout<<"Length of Linked List is "<<count<<endl;
//
//
//
//
//
//    return 1;
//}



Node * FindBeginOfLoop(Node *head){
    
    
    struct Node *slowPtr=head,*fastPtr=head;
    int loopExists=0;
    int count=2;
    while(slowPtr && fastPtr && fastPtr->next){
        count++;
        
        slowPtr=slowPtr->next;
        fastPtr=fastPtr->next->next;
        
        
        if (slowPtr== fastPtr){
            loopExists=1;
            break;
        }
        
    }
    
   
    cout<<"Length of Linked List is: "<<count<<endl;
    
    
    if(loopExists){
        slowPtr=head;
        while (slowPtr!=fastPtr) {
            fastPtr=fastPtr->next;
            slowPtr=slowPtr->next;
        }
        cout<<"Loop begins at this Node address: "<<slowPtr<<" and  its data is "<<slowPtr->data<<endl;
        return  slowPtr;
        
        
    }
    
    
    return  NULL;
}


int main() {
    
    int arr[]={1,2,3,4,5,6,7,9,10};
    
    CreateLinkedList(arr,9);

    FindBeginOfLoop(first);
  
}
