//
//  main.cpp
//  GenerateN-BitsBinaryString\
//
//  Created by princeraj on 17/04/21.
//

/*
 
 
 //Generate all the strings of n bits. Assume A[0..n – 1] is an array of size n.

 //backtracking approach used
 
 input-3
 
 output:-
             0 0 0
             0 0 1
             0 1 0
             0 1 1
             1 0 0
             1 0 1
             1 1 0
             1 1 1
 
 */





#include <iostream>
using  namespace::std;



//Another method to produce n-bits string, it will output string in a unordered way. 00,10 can be there instead of 00,01,then 10 and 11
void Binary(int n,char A[]){
    
    if(n<1){
        printf("%s\n",A);
    }else{
        
        A[n-1]='0';
        Binary(n-1,A);
        A[n-1]='1';
        Binary(n-1,A);
    }
}

//Generate n-bits string in a ordered form like 00, 01,10,11
void GenerateNbitsBinaryStrings(int n,int arr[], int i){
    
    
    
    if(i==n){
        for(int j=0;j<n;j++){
            cout<<arr[j]<<" ";
      
        }
        cout<<endl;
        return;
    }
    
    
    arr[i]=0;
    GenerateNbitsBinaryStrings(n, arr, i+1);
    
    arr[i]=1;
    GenerateNbitsBinaryStrings(n, arr, i+1);
    
    
    
    
    
}









//main function
int main()
{
//    int n;
//    cin>>n;
//    int arr[n];
//
//    GenerateNbitsBinaryStrings(n, arr, 0);
    int n;
    cin>>n;
    char A[n];
    Binary(n, A);
}




