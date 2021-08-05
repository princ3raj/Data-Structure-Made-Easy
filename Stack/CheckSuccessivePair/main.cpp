//
//  main.cpp
//  CheckSuccessivePair
//
//  Created by princeraj on 02/08/21.
//

/*
 Problem-27  Given a stack of integers, how do you check whether each successive pair of numbers in the stack is consecutive or not. The pairs can be increasing or decreasing, and if the stack has an odd number of elements, the element at the top is left out of a pair. For example, if the stack of elements are [4, 5, -2, -3, 11, 10, 5, 6, 20], then the output should be true because each of the pairs (4, 5), (-2, -3), (11, 10), and (5, 6) consists of consecutive numbers.
 */

#include <iostream>
#include <stack>
using namespace std;

stack<int> s;



int checkSuccessivePair(){
    int temp1,temp2,flag=2;
    
    if(s.size()%2!=0){
        s.pop();
    }
    while(!s.empty()){
        temp1=s.top(),s.pop();
        temp2=s.top(),s.pop();
        
        if(temp1+1!=temp2) flag--;
        
        if (temp1-1!=temp2) flag--;
        
        if(flag==0) return false;
        
        flag=2;
        
    }

    return true;
}

int main() {
    
    int arr[9]={4,5,-2,-3,11,10,5,6};
    for(int i=0;i<9;i++) s.push(arr[i]);
    
    cout<<checkSuccessivePair();
    
    
    
    

}
