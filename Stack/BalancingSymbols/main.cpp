//
//  main.cpp
//  BalancingSymbols
//
//  Created by princeraj on 05/05/21.
//

/*
 
 
 Problem-1  Discuss how stacks can be used for checking balancing of symbols.
 Solution: Stacks can be used to check whether the given expression has balanced symbols. This algorithm is very useful in compilers. Each time the parser reads one character at a time. If the character is an opening delimiter such as (, {, or [- then it is written to the stack. When a closing delimiter is encountered like ), }, or ]-the stack is popped.
 The opening and closing delimiters are then compared. If they match, the parsing of the string continues. If they do not match, the parser indicates that there is an error on the line. A linear-time O(n) algorithm based on stack can be given as:
 
 Time Complexity: O(n). Since we are scanning the input only once. Space Complexity: O(n) [for stack].
 
 */

#include <iostream>
#include "StackUsingArray.h"
#include <string>
using namespace std;





int main() {
    
    
  
    string symbols="()(()[()])";

    
    long len=symbols.length();
    
    Stack stack(len);
    
    for(int i=0;i<len;i++){
        
        if(symbols[i]=='(' || symbols[i]=='['|| symbols[i]=='{'){
            stack.push(symbols[i]);

        }else if (symbols[i]==')' || symbols[i]==']'|| symbols[i]=='}'){
            
            char value=stack.pop();
            if(value=='(' && symbols[i]==')'){
             
                continue;
            }
           else  if(value=='{' && symbols[i]=='}'){
        
               continue;
            }
            
           else if(value=='[' && symbols[i]==']'){
               continue;
            }
            
            stack.push(value);
            stack.push(symbols[i]);
            
        }
       
    }
    
  
    if(stack.isEmpty()){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    
    
}
    
