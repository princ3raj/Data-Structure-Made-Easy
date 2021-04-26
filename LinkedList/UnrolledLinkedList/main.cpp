//
//  main.cpp
//  UnrolledLinkedList
//
//  Created by princeraj on 25/04/21.
//

#include <iostream>
using namespace std;



struct Node{
    int num_elements=0;
    int arr[3];
    Node *next;
}*first=NULL;







void CreateUnrolledLL(int arr[],int n){
    
   
    
    Node *p,*q;
    q=NULL;
    
    first=new Node;
    first->next=NULL;
    first->arr[0]=arr[0];
    first->arr[1]=arr[1];
    first->arr[2]=arr[2];
    first->num_elements=3;
    p=first;
    
    
    for(int i=3;i<n;i++){
        
        if(p->next==NULL){
            q=new Node;
            p->next=q;
        }
       
        q->arr[q->num_elements]=arr[i];
        q->num_elements++;
        
        if(q->num_elements==3){
            
            q->next=NULL;
            p=q;
            
        }
        
    }
    
}


// Unrolled Linked List Traversal
void DisplayLinkedList(Node *p){
    
    int i=0;
    
    while(p){
        cout<<p->arr[i]<<" ";
        i++;
        if(i==3){
            i=0;
            p=p->next;
        }
    }
    
    cout<<endl;
}


//when No empty Nodes are available then call this function to create one
//Inserting at intermediary Node
void InsertInUnrolledLinkedList(int arr[], int n, int position){
    
    Node *p=first;
    Node *q=first->next;
    
    
    for(int i=1;i<position;i++){
        
        p=p->next;
        q=q->next;
        
    }
    
    Node *r=new Node;
    r->next=NULL;
    
    for(int j=0;j<n;j++){
        
        r->arr[j]=arr[j];
        r->num_elements++;
    
    }
    
   
    p->next=r;
    r->next=q;
}


//call this when you are adding one element and if there's space available in previous node for it to be inserted
void insertOnlyOneElement(int data){
    
    Node *p=new Node;
    p=first;
    while(p!=NULL){
        p=p->next;
        
        if(p->num_elements!=3){
            break;
        }
    }
    p->arr[p->num_elements]=data;
    p->num_elements++;

}








int main() {
    
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12};
    
    
    int arr_1[]={31};
    
    CreateUnrolledLL(arr,12);
    
    DisplayLinkedList(first);
    
    
    
    
    InsertInUnrolledLinkedList(arr_1,1,1);
    DisplayLinkedList(first);
    
    cout<<"Insert only one element"<<endl;
    insertOnlyOneElement(32);
    
    DisplayLinkedList(first);
    
    insertOnlyOneElement(33);
    
    DisplayLinkedList(first);
    
    
 
}
