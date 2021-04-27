//
//  chains.h
//  LinkedList
//
//  Created by princeraj on 27/04/21.
//

#ifndef chains_h
#define chains_h
#include <iostream>
using namespace std;


class Node{
    
public:
    int data;
    Node *next;
};


class HashTable{
    
    

    
public:
    
    Node *arr[10];
    
    
    //initializing every pointer to NULL
    HashTable(){
        for(int i=0;i<10;i++)
        arr[i]=NULL;
    }
    
    
    
    //return the index where the key should be added
    int HashFunction(int x){
        return x%10;
    }
    
    
    
    
    void insert(int x){
        //if count will be zero throught while running into while loop means we are inserting at 1st index
        int count=0;
        
        //flag variable indicates that if any of the condition runs then it becomes 0 and prevent other if conditions to run; which is after the while loop
        int flag=1;
        
        //getting the index
        int index=HashFunction(x);
        
        
        //checking is it the first time we are adding any element to this index
        if(arr[index]==NULL){
            
            Node *p=new Node;
            p->data=x;
            p->next=NULL;
            arr[index]=p;
        }else{
            
            
            //it'll always run whenever there is already a node present
            Node *p=new Node;
            p->data=x;
            p->next=NULL;
            Node *s=NULL;
            Node *q=arr[index];
            while(q!=NULL){
                
                
                //for inserting at 1st index
                if(q->data>=x && count==0){
                  
                    flag=0;
                    Node *r=NULL;
                    r=q;
                    arr[index]=p;
                    p->next=r;
                    break;
                }
                
                
                //for inserting at mid
                if(q->data>=x && count>=1){
                    
                    flag=0;
                    s->next=p;
                    p->next=q;
                    break;
                }
                count++;
            
                    s=q;
                    q=q->next;
                
        
            }//while loop end here
            
            //for inserting after last node
            // it will run when an element greater than every node will be added
            if(flag){
                s->next=p;
            }
           
            
        }//else block end here
    
    }
    
    
    void search(int x){
        int index=HashFunction(x);
        Node *p=arr[index];
        
        while(p!=NULL && p->data!=x){
            
            p=p->next;
            
        }
    
        //when becomes NULL means there is not such element in LinkedList
        if(p!=NULL){
            cout<<p->data<<" is found at this address "<<p<<endl;
        }else{
            cout<<x<<" Not Found"<<endl;
        }
       
    }
    
    
    
    void Delete(int x){
        
        int index=HashFunction(x);
        int count=1;
        Node *p=arr[index];
        Node *r=NULL;
        
        while(p!=NULL && p->data!=x){
            r=p;
            p=p->next;
            count++;
        
        }
        
        if(p!=NULL){
            
            
            if(count==1){
                Node *q=p->next;

                delete p;
                
                arr[index]=q;
            }
            
            if(count>=2){
                
                r->next=p->next;
                delete p;
            }
            
        }else{
            cout<<x<<" Not Found"<<endl;
        }
        
        
       
        
    }
    
    
 
    
    
    
    void Display(){
        for(int i=0;i<10;i++){
            
            Node *p=arr[i];
            
            while(p){
                
                cout<<p->data<<" ";
                p=p->next;
                
            }
            if(arr[i]!=NULL){
                cout<<endl;
            }
          
            
        }
        
        cout<<endl;
    }

}; //class end here


#endif /* chains_h */
