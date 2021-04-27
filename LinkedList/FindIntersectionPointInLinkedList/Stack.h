//
//  Stack.h
//  LinkedList
//
//  Created by princeraj on 27/04/21.
//

#ifndef Stack_h
#define Stack_h



class Stack{
    
public:
    long data;
    Stack *next;
    
};

class LinkedList{
    
private:
    Stack *first;
    Stack *last;

public:
    
    //when the constructor called itself, it will create a dummy linked list
    LinkedList(long arr[],int n){
        
        Stack *p,*q=NULL;
        first=new Stack();
        first->data=arr[0];
        first->next=NULL;
        p=first;
        
        
        for(int i=1;i<n;i++){
            q=new Stack();
            q->data=arr[i];
            q->next=NULL;
            p->next=q;
            p=q;
            
        }

    }
    
    void Display(){
        
        Stack *p=first;

        while(p){
            cout<<p->data<<" ";
            p=p->next;
        }
        
        cout<<endl;
    }
    
    void push(long data){
        
        
        Stack *p=first;
 
        
        while(p->next!=NULL){
            p=p->next;
            
        }
    
        Stack *r=new Stack();
        r->data=data;
        r->next=NULL;
        p->next=r;
        p=r;
        
        
    
    }
    
    
    
    long pop(){
        
        Stack *p=first->next;
        Stack *q=first;
        
        while (p->next!=NULL) {
            
            
            q=q->next;
            p=p->next;
            
        }
        
        q->next=NULL;
        
        long temp=p->data;
        
        
        delete p;
        
        
        return temp;
       
       
    }
    
    
    
    
    
};



#endif /* Stack_h */
