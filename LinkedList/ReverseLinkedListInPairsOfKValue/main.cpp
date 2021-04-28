//
//  main.cpp
//  ReverseLinkedListInPairsOfKValue
//
//  Created by princeraj on 28/04/21.
//


/*
 
 Problem-38 For a given K value (K > 0) reverse blocks of K nodes in a list.
 Example: Input: 1 2 3 4 5 6 7 8 9 10. Output for different K values:
 For K = 2: 2 1 4 3 6 5 8 7 10 9
 For K = 3: 3 2 1 6 5 4 9 8 7 10
 For K = 4: 4 3 2 1 8 7 6 5 9 10
 Solution:
 Algorithm: This is an extension of swapping nodes in a linked list.
 1) Check if remaining list has K nodes.
 a. If yes get the pointer of K + 1th node.
 b. Else return.
 2) Reverse first K nodes.
 3) Set next of last node (after reversal) to K + 1th node.
 4) Move to K + 1th node.
 5) Go to step 1.
 6) K – 1th node of first K nodes becomes the new head if available. Otherwise, we can
 return the head.
 
 
 this question isn't completed yet, the solution has some mistakes
 i'll try out later
 
 */





/*
 
 
 Problem-39 Is it possible to get O(1) access time for Linked Lists?
 Solution: Yes. Create a linked list and at the same time keep it in a hash table. For n elements we
 have to keep all the elements in a hash table which gives a preprocessing time of O(n).To read
 any element we require only constant time O(1) and to read n elements we require n * 1 unit of
 time = n units. Hence by using amortized analysis we can say that element access can be
 performed within O(1) time.
 Time Complexity – O(1) [Amortized]. Space Complexity - O(n) for Hash Table.
 
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






struct Node *GetKPlusOneThNode(int K, struct Node *head){

    struct Node *Kth;
    int i=0;
    if(!head){
        return head;
    }
    
    for(i=0, Kth=head;Kth && (i<K) ; i++,Kth=Kth->next);
    
    if(i==K && Kth!=NULL)
        return Kth;
    return head->next;
}

int HasKNodes(struct Node *head, int K){
    
    int i=0;
    for(i=0;head && (i<K); i++,head=head->next);
    
    if(i==K)
        return 1;
    return 0;
    
}


struct Node *ReverseBlockOfK_nodesInLinkedList(Node *head, int K){
    
    
    Node *cur=head, *temp, *next, *newHead;
    
    int i;
    
    if(K==0 || K==1)
        return head;
    
    if(HasKNodes(cur, K-1))
        newHead=GetKPlusOneThNode(K-1, cur);
    else
        newHead=head;
    
    while(cur && HasKNodes(cur, K)){
        
        temp=GetKPlusOneThNode(K, cur);
        i=0;
        
        while(i<K){
            
            next=cur->next;
            cur->next=temp;
            temp=cur;
            cur=next;
            i++;
            
            
        }
        
        
    }
    
    return newHead;
    
    
    
    
    
    
    
}


void DisplayLinkedList(struct Node *p){
    
    
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
}




int main() {
    
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12};


    CreateLinkedList(arr, 12);
    
    Node *finalHead=ReverseBlockOfK_nodesInLinkedList(first, 3);
    
    DisplayLinkedList(finalHead);

    
    
}
