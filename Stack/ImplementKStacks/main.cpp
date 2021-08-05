//
//  main.cpp
//  ImplementKStacks
//
//  Created by princeraj on 12/06/21.
//

/*
 
 Problem-17  Multiple (m) stacks in one array: Similar to Problem-15, what if we want to implement m stacks in one array?
 
 
 solution:-read the code, btw i have fixed the code,probably no error at this time
 */

#include <iostream>
using namespace std;


struct Stack{
    
    int free;
    int size_of_full_array;
    int size_of_nth_stack;
    int *top;
    signed int *p;
    
};


//Globally declared
Stack stack;



void push(int stackId,int num){
    int id=stackId-1;
    if(stack.free==stack.size_of_full_array){
        cout<<"complete stack is full"<<endl;
        return;
    }
    
    if(stack.top[id]==stack.size_of_nth_stack-1){
        
     
            
            int limit=stack.size_of_full_array/stack.size_of_nth_stack;
            for(int i=0;i<limit;i++){
                if(stack.top[i]<2){
                    push(i+1,num);
                    return;
                }
            }
            
            
            
        
       //maybe this one more condition can be removed
    }
    
//    else if(stack.top[id]==-1){
//
//        stack.p[stack.size_of_nth_stack*id]=num;
//        stack.top[id]++;
//        stack.free++;
//
//
//    }
    else{
        
        stack.p[stack.size_of_nth_stack*id+1+stack.top[id]]=num;
        stack.top[id]++;
        stack.free++;


    }
    
    
    
}

void pop(int stackId){
    int id=stack.top[stackId-1];
    int size=stack.size_of_nth_stack;
    int index=(stackId-1)*size+id;
    
    if(id==-1){
        cout<<"Stack underflow"<<endl;
        return;
    }else{
        stack.p[index]=NULL;
        stack.top[stackId-1]--;
        stack.free--;
        
    }
    
    
    
}

int empty(){
    int limit=stack.size_of_full_array/stack.size_of_nth_stack;
    for(int i=0;i<limit;i++){
        if(stack.top[i]!=-1){
            return 0;
        }
    }
    
    return 1;
    
   
    
}


void show(){
    
    if(empty()){
        cout<<"stack is empty"<<endl;
        
    }else{
        for(int i=0;i<stack.size_of_full_array;i++){
            
            cout<<stack.p[i]<<" ";
            
        }
    }
}

int main() {
    int k;
    cout<<"Enter size of the array"<<endl;
    cin>>stack.size_of_full_array;
    cout<<"Enter the no. of stack you want"<<endl;
    cin>>k;
    stack.size_of_nth_stack=stack.size_of_full_array/k;
    stack.free=0;
    stack.top=new int[stack.size_of_nth_stack]{-1,-1,-1};
    stack.p=new int[stack.size_of_full_array]{0};
    
    

    
    push(1,1);
    push(1,2);
    push(1,3);
    push(3,300);
    push(3,301);
    push(3,302);

    push(3,100);
    push(2,101);
    push(1,206);
    
//
//    pop(1);
//    pop(2);
//    pop(3);
//    pop(3);
//    pop(1);
//    pop(2);
//
//    pop(1);
//    pop(2);
//    pop(3);
//    pop(3);
//    pop(1);
//    pop(2);

 

  
    
    show();
    cout<<endl;

 
    

}



/*
 
 
 //
 //  main.cpp
 //  ImplementKStacks
 //
 //  Created by princeraj on 12/06/21.
 //


  
  Problem-17  Multiple (m) stacks in one array: Similar to Problem-15, what if we want to implement m stacks in one array?


 #include <iostream>
 using namespace std;


 struct Stack{
     
     int free;
     int size_of_full_array;
     int size_of_nth_stack;
     int *top;
     signed int *p;
     
 };


 //Globally declared
 Stack stack;



 void push(int stackId,int num){
     int id=stackId-1;
     if(stack.free==stack.size_of_full_array){
         cout<<"complete stack is full"<<endl;
         return;
     }
     
     if(stack.top[id]==stack.size_of_nth_stack-1){
         
      
             
             int limit=stack.size_of_full_array/stack.size_of_nth_stack;
             for(int i=0;i<limit;i++){
                 if(stack.top[i]<2){
                     push(i+1,num);
                     return;
                 }
             }
             
             
             
         
        //maybe this one more condition can be removed
     }else if(stack.top[id]==-1){
         
         stack.p[stack.size_of_nth_stack*id]=num;
         stack.top[id]++;
         stack.free++;
         
         
     }else{
         
         stack.p[stack.size_of_nth_stack*id+1+stack.top[id]]=num;
         stack.top[id]++;
         stack.free++;


     }
     
     
     
 }

 void pop(int stackId){
     int id=stack.top[stackId-1];
     int size=stack.size_of_nth_stack;
     int index=(stackId-1)*size+id;
     
     if(id==-1){
         cout<<"Stack underflow"<<endl;
         return;
     }else{
         stack.p[index]=NULL;
         stack.top[stackId-1]--;
         stack.free--;
         
     }
     
     
     
 }

 int empty(){
     int limit=stack.size_of_full_array/stack.size_of_nth_stack;
     for(int i=0;i<limit;i++){
         if(stack.top[i]!=-1){
             return 0;
         }
     }
     
     return 1;
     
    
     
 }


 void show(){
     
     if(empty()){
         cout<<"stack is empty"<<endl;
         
     }else{
         for(int i=0;i<stack.size_of_full_array;i++){
             
             cout<<stack.p[i]<<" ";
             
         }
     }
 }

 int main() {
     int k;
     cout<<"Enter size of the array"<<endl;
     cin>>stack.size_of_full_array;
     cout<<"Enter the no. of stack you want"<<endl;
     cin>>k;
     stack.size_of_nth_stack=stack.size_of_full_array/k;
     stack.free=0;
     stack.top=new int[stack.size_of_nth_stack]{-1,-1,-1};
     stack.p=new int[stack.size_of_full_array]{0};
     
     

     
     push(1,1);
     push(1,2);
     push(1,3);
     push(3,300);
     push(3,301);
     push(3,302);

     push(3,100);
     push(2,101);
     push(1,206);
     
     
     pop(1);
     pop(2);
     pop(3);
     pop(3);
     pop(1);
     pop(2);
     
     pop(1);
     pop(2);
     pop(3);
     pop(3);
     pop(1);
     pop(2);

  

   
     
     show();
     cout<<endl;

  
     

 }

 
 */
