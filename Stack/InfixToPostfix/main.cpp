//
//  main.cpp
//  InfixToPostfix
//
//  Created by princeraj on 09/06/21.
//



/*
 
 Problem-2  Discuss infix to postfix conversion algorithm using stack.
 
 Infix: An infix expression is a single letter, or an operator, proceeded by one infix string and followed by another Infix string.
 Prefix: A prefix expression is a single letter, or an operator, followed by two prefix strings. Every prefix string longer than a single variable contains an operator, first operand and second operand.
 Postfix: A postfix expression (also called Reverse Polish Notation) is a single letter or an operator, preceded by two postfix strings. Every postfix string longer than a single variable contains first and second operands followed by an operator.
 Prefix and postfix notions are methods of writing mathematical expressions without parenthesis. Time to evaluate a postfix and prefix expression is O(n), where n is the number of elements in the array.
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;




int Precedence(char c){
    
    if(c=='/' || c=='%' || c=='*')
        return 3;
    else if(c=='+' || c=='-')
        return 2;
    else if(c=='^')
        return 1;
    
    
    return NULL;
}






int main() {
    string result="";
    stack<char> s;
    string infix="a+b*c^d-e^f+g*h-i";
    
    long len=infix.length();
    
    
    for(int i=0;i<len;i++){
        
        
        if( (infix[i]>=65 && infix[i]<=90) || (infix[i]>=97 && infix[i]<=122)){
            
            result=result+infix[i];
        }
        
        else if(s.empty() && (infix[i]=='/' || infix[i]=='%'|| infix[i]=='*' || infix[i]=='+' || infix[i]=='-' || infix[i]=='^')){
            
            s.push(infix[i]);
            
            
         
        }else{
        
            while(Precedence(infix[i])>=Precedence(s.top()) || Precedence(infix[i])<Precedence(s.top())){
                
                if(Precedence(infix[i])>Precedence(s.top())){
                    s.push(infix[i]);
                    break;
                }
                
              
                int one=Precedence(s.top());
                int two=Precedence(infix[i]);
                
                if(two <=one){
                    
                    //pop and append
                    result=result+s.top();
                    s.pop();
                    
                    
                }else{
                    //push
                    s.push(infix[i]);
                }
                
                if(s.empty()){
                    s.push(infix[i]);
                    break;
                }
                
                
            }
            

            
        }
        
        
        
        
    }
    
    
    
    while(!s.empty()){
        
        result+=s.top();
        s.pop();
    
    }
    
    
    cout<<result<<endl;
    
    
    
    
    
    


    

    
    }
