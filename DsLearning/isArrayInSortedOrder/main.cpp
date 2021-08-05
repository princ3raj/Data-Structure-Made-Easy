//
//  main.cpp
//  isArrayInSortedOrder
//
//  Created by princeraj on 17/04/21.
//

/*
 
 Given an array, check whether the array is in sorted order with recursion.
 Time Complexity: O(n). Space Complexity: O(n) for recursive stack space.
 */


#include <iostream>
using namespace std;






int isArrayInSortedOrder(int arr[],int n){
    
    
    if(n==1){
        return 1;
    }
    
    return (arr[n-1]<arr[n-2]?0:isArrayInSortedOrder(arr, n-1));
}


int main() {
    
    int arr[5]={1,2,3,4,5};
    
    cout<<isArrayInSortedOrder(arr,5)<<endl;
    


}
