//
//  main.cpp
//  RecursivelyRemoveAdjacentDuplicates
//
//  Created by princeraj on 02/08/21.
//

#include <iostream>
#include <stack>
/*
 
 
 Problem-28  Recursively remove all adjacent duplicates: Given a string of characters, recursively remove adjacent duplicate characters from string. The output string should not have any adjacent duplicates.
 Solution: This solution runs with the concept of in-place stack. When element on stack doesn’t match the current character, we add it to stack. When it matches to stack top, we skip characters until the element matches the top of stack and remove the element from stack.
 
 Time Complexity: O(n). Space Complexity: O(1) as the stack simulation is done inplace
 */
using namespace::std;


void removeAdjacentDuplicates(char *str){
    
    
    int stkptr=-1;
    int i=0;
    int long len=strlen(str);
    while(i<len){
        
        if(stkptr==-1 || str[stkptr]!=str[i]){
            stkptr++;
            str[stkptr]=str[i];
            i++;
            
        }else{
            while (i<len && str[stkptr]==str[i]) i++;
                
            stkptr--;
        }
    }
    str[stkptr+1]='\0';
}




int main() {
    
    
    char s[]={'c','a','r','e','e','r','m','o','n','k'};
    removeAdjacentDuplicates(s);
    cout<<s<<endl;
  
}
