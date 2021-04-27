//
//  main.cpp
//  FindIntersectionPointInLinkedList
//
//  Created by princeraj on 26/04/21.
//

/*
 
 Problem-17 Suppose there are two singly linked lists both of which intersect at some point
 and become a single linked list. The head or start pointers of both the lists are known, but
 the intersecting node is not known. Also, the number of nodes in each of the lists before
 they intersect is unknown and may be different in each list. List1 may have n nodes before
 it reaches the intersection point, and List2 might have m nodes before it reaches the
 intersection point where m and n may be m = n,m < n or m > n. Give an algorithm for
 finding the merging point.
 
 Solution: Brute-Force Approach: One easy solution is to compare every node pointer in the first
 list with every other node pointer in the second list by which the matching node pointers will lead
 us to the intersecting node. But, the time complexity in this case will be O(mn) which will be
 high.
 
 Simply, find the intersection point of two linkedlist.
 
 In my opinion, this question can be solved using 2 method one if its a doubly linked list.
 we'll traverse to last node and then move backward until pointer of both nodes doesn't match
 once it stops matching, we will return pointers next address as the intersecting points.
 
 or you can have vector/stack/arrays to see the duplicate pointers address.
 
 
 This question has some other approach as well, let's see:
 
 Solution:- It can also be solved using Hashtable (Chaining)
 so In my header file, hashtable.h , complete implementation of hashtable has been done
 and then I am using a hextoLong converter function , in order to store a long value in data
 
 Using FindInterSection method, I am passing every Second Linked List Pointer Long value to Hashtable Search Method
 and if the key exists then I am return that Node data value which is itself a pointer address in Long format
 
 otherwise, returning NULL
 
 
 Time Complexity: Time for creating the hash table + Time for scanning the second list = O(m) +
 O(n) (or O(n) + O(m), depending on which list we select for creating the hash table. But in both
 cases the time complexity is the same. Space Complexity: O(n) or O(m).
 
 
 Let's Solve this question using stack, as i have already mentioned this solution above
 Time Complexity: O(m + n), for scanning both the lists.
 Space Complexity: O(m + n), for creating two stacks for both the lists.
 

 
 */


/*
 
 Problem-21 Is there any other way of solving Problem-17?
 Solution: Yes. Using “finding the first repeating number” approach in an array (for algorithm
 refer to Searching chapter).
 Algorithm:
 • Create an array A and keep all the next pointers of both the lists in the array.
 • In the array find the first repeating element [Refer to Searching chapter for
 algorithm].
 • The first repeating number indicates the merging point of both the lists.
 
 
 Time Complexity: O(m + n). Space Complexity: O(m + n)./
 
 btw the code, i have written for this findingIntersectionUsingArray is not of the same complexity as mentioned here, as far as  i know.
 so i might update that code later.
 
 */


/*
 
 Problem-22 Can we still think of finding an alternative solution for Problem-17?
 Solution: Yes. By combining sorting and search techniques we can reduce the complexity.
 Algorithm:
 • Create an array A and keep all the next pointers of the first list in the array.
 • Sort these array elements.
 • Then, for each of the second list elements, search in the sorted array (let us assume
 that we are using binary search which gives O(logn)).
 • Since we are scanning the second list one by one, the first repeating element that
 appears in the array is nothing but the merging point.
 Time Complexity: Time for sorting + Time for searching = O(Max(mlogm, nlogn)).
 Space Complexity: O(Max(m, n)).
 
 */



#include <sstream>
#include <iostream>
#include "hashtable.h"
#include "Stack.h"
#include <string>
using namespace std;


struct Node{
    
    int data;
    Node *next;
}*first=NULL,*second=NULL,*Intersection=NULL;


long arr_for_stack[]={NULL};

//Global Object for hashtable
HashTable hashtable;

//Global variable for stack;
LinkedList Stack_one(arr_for_stack,1);
LinkedList Stack_two(arr_for_stack,1);


// this function converts an pointer which is in hex into Long value
long ConvertHexToLongInteger(Node *p){
    
    
    const void * address = static_cast<const void*>(p);
    std::stringstream ss;
    ss << address;
    std::string name = ss.str();
    
    return stol(name, 0, 16);
}








void FirstLinkedList(int arr[], int n){
    
    Node *p=NULL,*q=NULL;
    first=new Node;
    first->data=arr[0];
    first->next=NULL;
    p=first;
    
   
    hashtable.insert(ConvertHexToLongInteger(p));
    Stack_one.push(ConvertHexToLongInteger(p));
    
    
    
    for(int i=1;i<n;i++){
        q=new Node;
        q->data=arr[i];
        q->next=NULL;
        p->next=q;
        p=q;
        hashtable.insert(ConvertHexToLongInteger(p));
        Stack_one.push(ConvertHexToLongInteger(p));
    
    }
    
    
    
    
}



void SecondLinkedList(int arr[], int n){
    
    Node *p=NULL,*q=NULL;
    second=new Node;
    second->data=arr[0];
    second->next=NULL;
    p=second;
    
    
    
    for(int i=1;i<n;i++){
        
        q=new Node;
        q->data=arr[i];
        q->next=NULL;
        p->next=q;
        p=q;
    
    
    }
    
    //this line is creating intersection b/w both lists
    p->next=first->next->next;
    p=second;
    while(p){
        Stack_two.push(ConvertHexToLongInteger(p));
        p=p->next;
    }
    
}







void DisplayLinkedList(Node *p){
    

    
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    
    cout<<endl;
}


void FindInterSectionAddress(Node *p){
    
    
    while(p){
        
        if(hashtable.search(ConvertHexToLongInteger(p))){
            
            cout<<"Node address "<<p<<" where both are intersecting and data on that node: "<<p->data<<endl;
            
            break;
        }
        p=p->next;
        
    }
    
    if(p==NULL){
        
        cout<<"There is not any intersecting points"<<endl;
        
    }
    
    
}


void FindInterSectionUsingStack(long key){
    
    Node *p=first;
    
    while(p){
        
        long temp=ConvertHexToLongInteger(p);
        if(temp==key){
            
            cout<<"They are intersecting at address "<<p->next<<" data is: "<<p->next->data<<endl;
            break;
        }
        p=p->next;
    
    }
}



void FindIntersectionUsingArray(Node *s){
    Node *p=first;
    Node *arr[50];
    Node *result=NULL;
    
    for(int k=0;k<50;k++){
        arr[k]=NULL;
    }
    
    //for inserting second LinkedList pointer
    s=second;
    int i=0;
    while(s){
        arr[i]=s;
        s=s->next;
        i++;
    }
  
    // for inserting first LinkedList pointer
    while(p){
        arr[i]=p;
        p=p->next;
        i++;
        
    }
    
    
    int l=0,m=0;
    while(true){
        
        if(arr[l]==arr[++m]){
            
            result=arr[l];
            cout<<"Intersecting Node address: "<<result<<" Data is :"<<result->data<<endl;
            
            break;
        }
        
        if(m>=50){
            l++;
            m=l;
        }
        
        if(l>=50){
            break;
        }
        
        
        
        
        
        
        
        
    }
    
    
    
}






int main() {
    
    
    long result;
    
    int arr_1[]={1,2,3,4,5};
    int arr_2[]={10,11,12,13,14};
    
    
    FirstLinkedList(arr_1, 5);
    
    SecondLinkedList(arr_2,5);
    
    DisplayLinkedList(first);
    DisplayLinkedList(second);
    
    
    cout<<"*******Hashtable Method******"<<endl;
    FindInterSectionAddress(second);
    
    cout<<endl;
    
    
    cout<<"Stack :1"<<endl;
    Stack_one.Display();
    
    cout<<"Stack :2"<<endl;
    Stack_two.Display();
    
    cout<<"********Stack Method********"<<endl;
    
    // for getting the value of the Node where addresses of both Nodes become different
    while(true){
        
        long temp_1=Stack_one.pop();
        long temp_2=Stack_two.pop();
        
        if(temp_1!=temp_2){
            
            result=temp_1;
            break;
            
            
        }
        
        
    }
    
    FindInterSectionUsingStack(result);
    
    
    cout<<endl;
    FindIntersectionUsingArray(second);
    
    

  
}
