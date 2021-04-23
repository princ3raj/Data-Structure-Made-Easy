//
//  main.cpp
//  Insert&DeleteOperationLinkedList
//
//  Created by princeraj on 20/04/21.
//


/*
 
 this module contains all the method for inserting in a linked list like inserting at first, last and mid and even there's a combine function which can do all
 
 also it contains deleting at first and at given position
 
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


void insertLinkedListAtFirst(int insert_number){
    
    Node *q;
    q=new Node;
    q->data=insert_number;
    q->next=first;
    first=q;

}

void insertLinkedListMid(Node *p,int insert_number, int position){
    Node *q;
    
    while(position>1){
        
        
        p=p->next;
        position--;
        
    }
    
    q=new Node;
    q->data=insert_number;
    q->next=p->next;
    p->next=q;
    
}


void insertLinkedListAtLast(Node *p, int insert_number){
    Node *q=NULL;
    Node *r;
    
    while(p){
        q=p;
        p=p->next;
    }
    
  
        r=new Node;
        r->data=insert_number;
        r->next=NULL;
        q->next=r;
    
}


void insertElementAtAnywhereInLinkedList(Node *p,int number,int position){
    
    
    if(position==0){
        
        insertLinkedListAtFirst(number);
        
    }else{
        
        insertLinkedListMid(first, number, position);
        
    }
    
}


/*
 Delete Operation Functions
 */

void DeleteAtFirstPosition(Node *p){
    
    
    first=p->next;
    delete p;
    
}

void DeleteAtGivenPosition(Node *p,int position){
    Node *q=NULL;
    while(position>1){
        
        q=p;
        p=p->next;
       
      
        
        position--;
        
        
    }
    q->next=p->next;
    delete p;

}





int main() {
    
    
    int arr[]={1,2,3,46,1,23,45,11,2,64};
    
    
    CreateLinkedList(arr, 10);
   
    RecursiveDisplay(first);
    cout<<endl;
    
//    insertLinkedListAtLast(first, 101);
//    insertLinkedListAtLast(first, 201);
//    insertLinkedListAtLast(first, 121);
//    insertLinkedListAtLast(first, 111);
//    insertLinkedListAtFirst(88);
//    insertLinkedListAtFirst(88);
//    RecursiveDisplay(first);
//    cout<<endl;
    
//    insertLinkedListMid(first, 999, 2);
//    RecursiveDisplay(first);
//    cout<<endl;
//
//
//    insertLinkedListMid(first, 1000, 16);
//    RecursiveDisplay(first);
//    cout<<endl;
//
//    insertLinkedListMid(first, 1111, 11);
//    RecursiveDisplay(first);
//    cout<<endl;
//
//    insertLinkedListMid(first, 777, 1);
//    RecursiveDisplay(first);
//    cout<<endl;
//
//
//    //it will also work for adding an element at the last Node
//    insertLinkedListMid(first, 2020, 20);
//    RecursiveDisplay(first);
//    cout<<endl;
    
    //One Function for all type insertion
    
    insertElementAtAnywhereInLinkedList(first, 23, 0);
    RecursiveDisplay(first);
    cout<<endl;
    
    insertElementAtAnywhereInLinkedList(first, 111, 11);
    RecursiveDisplay(first);
    cout<<endl;
    
    insertElementAtAnywhereInLinkedList(first, 2344, 5);
    RecursiveDisplay(first);
    cout<<endl;
    
//    DeleteAtFirstPosition(first);
//    RecursiveDisplay(first);
//    cout<<endl;
//
//    DeleteAtFirstPosition(first);
//    RecursiveDisplay(first);
//    cout<<endl;
    
    cout<<"Deletion start from here on:"<<endl;
   
    

    DeleteAtGivenPosition(first,3);
    RecursiveDisplay(first);
    cout<<endl;
    
    DeleteAtGivenPosition(first,12);
    RecursiveDisplay(first);
    cout<<endl;
    
    DeleteAtGivenPosition(first,5);
    RecursiveDisplay(first);
    cout<<endl;
    
    
    

}
