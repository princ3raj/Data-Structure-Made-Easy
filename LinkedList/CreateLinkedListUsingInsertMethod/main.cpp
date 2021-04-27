//
//  main.cpp
//  CreateLinkedListUsingInsertMethod
//
//  Created by princeraj on 20/04/21.
//



/*
 
 this module contains insert functions mentioned as follows:
 I) it create link list using insert statement
 II) it inserts element using Last Pointer
 III) it also inserts element in sorted order
 
 
 Problem-15 Insert a node in a sorted linked list.
 It contains function named insertInSortedLinkedlist which can do that
 
 */

#include <iostream>
using namespace std;


struct Node{
    
    int data;
    struct Node *next;
}*first=NULL,*last=NULL;







void insertElementUsingLastPointer(Node *q,int number){
    
    Node *r;
    
    
    r=new Node;
    r->data=number;
    r->next=NULL;
    last->next=r;
    last=r;
    
}




void insertLinkedListAtFirst(int insert_number){
    
    Node *q;
    q=new Node;
    q->data=insert_number;
    q->next=first;
    first=q;
    last=q;

}

void insertLinkedListMid(Node *p,int insert_number, int position){
    Node *q;
    
    //second condition used to prevent user from entering a position which doesn't exist.
    while(position>1&&p->next!=NULL){
        
        
        p=p->next;
        position--;
        
    }
    
    q=new Node;
    q->data=insert_number;
    q->next=p->next;
    p->next=q;
    last=q;
    
}

void insertElementAtAnywhereInLinkedList(Node *p,int number,int position){
    
    
    if(position==0){
        
        insertLinkedListAtFirst(number);
        
    }else{
        
        insertLinkedListMid(first, number, position);
        
    }
    
}

void createLinkedList(Node *p,int number, int position){
    
    Node *q;
    
    if(!first){
        
        q=new Node;
        q->data=number;
        q->next=NULL;
        first=q;
        last=q;
        
    }else{
        
        insertElementAtAnywhereInLinkedList(first, number, position);
    
        
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



void insertingInSortedLinkedList(Node *p,int number){
    
    int position=0;
    
    if(p->data>number){
        
        insertLinkedListAtFirst(number);
       
        
    }else{
        
        while(p->next){
            
            position++;
            
            p=p->next;
            
            if(p->data>number){
                
      
                
                insertLinkedListMid(first, number, position);
                break;
                
            }else if(p->next==NULL){
                
               
                
                
                position=position+1;
                insertElementAtAnywhereInLinkedList(first, number, position);
                
                last=p;
                // this helps last pointer to point to the last element as here p is pointing the last element
                
              
                break;
                //when there isn't any break statement it goes into infinite loop. Really i don't know why as it should break itself when the while loop condition goes false.
               
            }
            
        }

        
        
        
    }
    
}

int CheckLikedListSortedOrNot(Node *p){
    
    Node *q=NULL;
    
    while(p){
        
        q=p;
        p=p->next;
        
        if(q->data>p->data){
            return 0;
        }
        
    }
    return 1;


    
    
    
    
    
}


int main() {
    
    
    createLinkedList(first, 1,NULL);
    createLinkedList(first, 2,1);
    createLinkedList(first, 3,2);
    createLinkedList(first, 4,3);
    createLinkedList(first, 5,4);
    createLinkedList(first, 6,5);
    
    //This Node Position Does Not Exist, even thereafter, it will not pop up error due to the condition being set on while loop in insertMidFunction, hence it will append it to the last Node.
    createLinkedList(first, 7,15);
    
    
    //true for this one as well, Node 1500 doesn't exist
    createLinkedList(first, 8,1500);
    
    
    
    RecursiveDisplay(first);
    cout<<endl;
    
    
    
    //Now we don't need to go to the last node everytime when we need to add an element to the last. as it is happening in our insertMid function, check out that function which works differently than this and using 2 pointers
    insertElementUsingLastPointer(last, 9);
    insertElementUsingLastPointer(last, 10);
    insertElementUsingLastPointer(last, 13);
    
    RecursiveDisplay(first);
    cout<<endl;
    
    insertingInSortedLinkedList(first, 0);
    RecursiveDisplay(first);
    cout<<endl;

    insertingInSortedLinkedList(first, 11);
    RecursiveDisplay(first);
    cout<<endl;

    insertingInSortedLinkedList(first, -1);
    RecursiveDisplay(first);
    cout<<endl;

    insertingInSortedLinkedList(first, 16);
    RecursiveDisplay(first);
    cout<<endl;


    insertingInSortedLinkedList(first, 100);
    RecursiveDisplay(first);
    cout<<endl;

    insertingInSortedLinkedList(first, 43);
    RecursiveDisplay(first);
    cout<<endl;


    insertingInSortedLinkedList(first, -17);
    RecursiveDisplay(first);
    cout<<endl;
    
    insertingInSortedLinkedList(first, 100);
    RecursiveDisplay(first);
    cout<<endl;
    
    
    
    /*insertUsingLast Function will only work properly when you previously added an large element than any on the presented node which takes the last pointer to pointing to the last node as i have
    written an expression for that : last=p, check that out*/
    
    insertElementUsingLastPointer(last, 10001);
    RecursiveDisplay(first);
    cout<<endl;
    
    
    
    
    /*Once InsertUsingSortFunction runs, then you better not call InsertUsingLastPointer as it would not point to the last node because of InsertUsingSortFunction()
    insertElementUsingLastPointer(last, 1001);
    RecursiveDisplay(first);

        cout<<endl;
     
     */
    
    
    
}
