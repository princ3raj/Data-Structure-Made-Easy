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
    
    for(int i=1;i<n;i++)
    {
        q=new Node;
        q->data=arr[i];
        q->next=NULL;
        p->next=q;
        p=p->next;
        
    }
    
    p->next=first;

    
}

void DisplayLinkedList(struct Node *p){

    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}



int CheckLinkedListIsInLoopOrNot(Node *p,Node *q){
    
    
    while(p!=q){
        
        q=q->next;
        q=q->next;
        q=q->next;
        q=q->next;
        p=p->next;
        
        if(p==NULL || q==NULL){
            return 0;
        }
    
        
        
    }
    
    return 1;
}


int main() {
    
    int arr[]={1,2,3,4,5};
    
    CreateLinkedList(arr,5);
//    DisplayLinkedList(first);
    
    
    int flag=CheckLinkedListIsInLoopOrNot(first, first);
    if(flag){
        cout<<"Linked list is in Loop"<<endl;
        
    }else{
        cout<<"Linked list is linear"<<endl;
        
    }
  
}
