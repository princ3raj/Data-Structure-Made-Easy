//
//  main.cpp
//  CheckIsStringPalindromeOrNot
//
//  Created by princeraj on 11/06/21.
//

/*
 
 Problem-8  Given an array of characters formed with a’s and b’s. The string is marked with special character X which represents the middle of the list (for example: ababa...ababXbabab baaa). Check whether the string is palindrome.
 
 solution:also can be solved using two stacks
 Time Complexity: O(n). Space Complexity: O(1).
 */

#include <iostream>
#include <stack>
using namespace std;

void checkPalindromeOrNot(string s){
    
    int flag;
    
    long len=s.length();
    
    int i;
    long end=len-1;
    
    if(len%2==0)
        len-=2;
    else
        len-=1;
    
    
    for(i=0;i<len;i++){
        if(s[i]==s[end]){
            flag=1;
            end--;
        }else{
            flag=0;
            cout<<"Not a Palindrome"<<endl;
            break;
        }
    }
    
    if(flag)
        cout<<"Palindrome"<<endl;
    
    
}



int main() {
    
    
    checkPalindromeOrNot("abbbbbbabbbbbba");
    
    
    

}
