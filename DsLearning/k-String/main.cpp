//
//  main.cpp
//  k-String
//
//  Created by princeraj on 17/04/21.
//

#include <iostream>
using namespace std;


/*Generate all the strings of length n drawn from 0... k – 1.
 it is completely simliar to GeneratingAllnBitsStrings with one difference, now the bits will be decided by k.
 
 for example n=2 means length of string will be of 2 like :00, 01
 and k decides the bits if k=3; the bits can be 0,1,and 2;
 
 if its 4 then k will be 0,1,2,3,4 and remember (k>=n)
 
 input n=2; k=3
 
 output:-
 0 0
 0 1
 0 2
 1 0
 1 1
 1 2
 2 0
 2 1
 2 2
 
 input=2 5
 
 output:-
 0 0
 0 1
 0 2
 0 3
 0 4
 1 0
 1 1
 1 2
 1 3
 1 4
 2 0
 2 1
 2 2
 2 3
 2 4
 3 0
 3 1
 3 2
 3 3
 3 4
 4 0
 4 1
 4 2
 4 3
 4 4
*/
void kString(int n, int arr[], int i, int k){
    

    if(i==n){
        for(int j=0;j<n;j++)
        cout<<arr[j]<<" ";
        
        cout<<endl;
        
        return;
    }
    
    for(int z=0;z<k;z++){
        
        arr[i]=z;
        kString(n, arr, i+1,k);
        
    }
     
    
    
}







int main() {
    
    int n;
    int k;
    cin>>n>>k;
    int arr[n];
    
    kString(n, arr, 0,k);
   
}
