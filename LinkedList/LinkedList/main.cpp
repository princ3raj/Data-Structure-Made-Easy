//
//  main.cpp
//  LinkedList
//
//  Created by princeraj on 20/04/21.
//

/*
 
 this module contain counting,display,sum, findmax and their recursive solutions, sometimes with two or more recursive approach.
 
 
 Remember here 'first' is the global pointer variable and it's holding the address of created LinkedList pointing onto the firts Node.
 
 */

/*
 
  For Linked List  there are 54 Problems in Narshimma Karamuchi including different approaches numbers as well
 */

int CountNodes=0;

int result=0;

#include <iostream>
#include <climits>
using namespace std;



//Globally declared Nodes and first pointer
struct Node{
    
    
    int data;
    struct Node *next;
    
}*first=NULL;




int SumOfLinkedList(struct Node *p){
    
    int sum=0;
    
    
    while(p){
        sum=sum+p->data;
        p=p->next;
        
    }
    
    return sum;
}




void DisplayLinkedList(struct Node *p){
    
    
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
}



void RecursiveDisplay(struct Node *s){
    
    if (s==NULL)
    {
        return;
    }
    CountNodes++;
    cout<<s->data<<endl;
    
    return RecursiveDisplay(s->next);
}




int RecursiveCount(struct Node *p){
    
    if(p==0){
        return 0;
    }
    
    return RecursiveCount(p->next)+1;
}





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




int RecursiveSumLinkedList(struct Node *p){
    
    
    if(p)
    {
        
        result=result+p->data;
        RecursiveSumLinkedList(p->next);
    }
    return result;
  
    
}





int RecursiveSumLinkedListAlternateWay(struct Node *p){
    
    if(p==0){
        return 0;
    }
    else{
        return RecursiveSumLinkedListAlternateWay(p->next)+p->data;
    }
}


int FindMaxInLinkedList(struct Node *p){
    
    int max=0;
    
    while(p){
        
        if(p->data > max){
            max=p->data;
        
        }
        
        p=p->next;
        
    }
    
    return max;
    
}



//Doubt in Tracing it
int RecursiveFindMaxInLinkedList(struct Node *p,int max){
    
    if(p==NULL){
        return max;
    }
    
    
    
    
    if(p->data>max)
        max=p->data;
    
    return RecursiveFindMaxInLinkedList(p->next, max);
    
  
  
    
}


int RecursiveFindMaxInLinkedListNewWay(struct Node *p){
    
    
    int x=0;
    if(p==0){
        return INT_MIN;
        
    }
         
        x=RecursiveFindMaxInLinkedListNewWay(p->next);
        
        return x>p->data?x:p->data;
        
        
//        if(x>p->data)
//            return x;
//        else
//            return p->data;
    
}


int main() {
    
    
    int arr[]={1,2,3,46,1,23,45,11,2,64};
    
    
    CreateLinkedList(arr, 10);
    DisplayLinkedList(first);
    
    cout<<endl;
    
    RecursiveDisplay(first);
    
    cout<<CountNodes<<endl;
    
    cout<<endl;
    cout<<RecursiveCount(first)<<endl;
    
    cout<<"sum of all linked elements are: "<<SumOfLinkedList(first)<<endl;
    
    
    cout<<"RECURSIVE SUM"<<endl;
    
    
    
    
    cout<<RecursiveSumLinkedList(first)<<endl;
    
    cout<<"Alternate Recursive sum of Linked List"<<endl;
    
    cout<<RecursiveSumLinkedListAlternateWay(first)<<endl;
    
    cout<<"Finding Max in a Linked List: "<<endl;
    
    cout<<FindMaxInLinkedList(first)<<endl;
    
    
    cout<<endl;
    
    cout<<"Recursive Way to Find Max in a Linked List"<<endl;
    
    cout<<RecursiveFindMaxInLinkedList(first,0)<<endl;
    
    cout<<"New Recursive Solution for finding max in a Linked List"<<endl;
    
    cout<<RecursiveFindMaxInLinkedListNewWay(first)<<endl;
    
    
}
