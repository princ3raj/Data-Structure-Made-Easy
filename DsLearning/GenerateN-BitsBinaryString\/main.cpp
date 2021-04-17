//
//  main.cpp
//  GenerateN-BitsBinaryString\
//
//  Created by princeraj on 17/04/21.
//

#include <iostream>
using  namespace::std;


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
    int n;
    cin>>n;
    int arr[n];
    
    GenerateNbitsBinaryStrings(n, arr, 0);
}




