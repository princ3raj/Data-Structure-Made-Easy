//
//  main.cpp
//  InfixtoPostfix_Second
//
//  Created by princeraj on 09/06/21.
//

/*
 input:
 a+b*(c^d-e)^(f+g*h)-i

 output:
 abcd^e-fgh*+^*+i-
 
 
 incompelete solution for evaluation part
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;




vector<int> weight;






int outstack(char c){
    
    
    if(c=='(')
        return 7;
    else if(c=='^')
        return 6;
    else if(c=='*'|| c=='/'|| c=='%')
        return 3;
    else if(c=='+'|| c=='-')
        return 1;
    else if(c==')')
        return 0;
    
    
    
    return NULL;
    
}


int instack(char c){
    
    
    if(c=='(')
        return 0;
    else if(c=='^')
        return 5;
    else if(c=='*'|| c=='/'|| c=='%')
        return 4;
    else if(c=='+'|| c=='-')
        return 2;

    
    
    
    
    return NULL;
    
}

int isOperandOrOperator(char c){
    
    if(c=='+'|| c=='/'||c=='*'|| c=='%' || c=='('||c==')'||c=='-'||c=='^'){
        
        return 1;
        
    }else{
        return 0;
    }
    
}


string infixToPostfix(string s){
    string result="";
    int flag=1;
    long len= s.length();
    stack<char> Stack;
    
    
    if(isOperandOrOperator(s[0])){
    
        Stack.push(s[0]);
    }else{
        result+=s[0];
       
    }
    

    
    
    for(int i=1;i<len;i++)
    
    {
        flag=1;
      
        

            if(isOperandOrOperator(s[i])==1)
            {
                
                if(s[i]==')' && s.length()==i-1){
                   
                }else{
                    weight.push_back(i);
                }
                    
             
               
            
                    while(flag==1){
                        
                        
                        
                                    if(Stack.empty()){
                                        
                                     
                                        Stack.push(s[i]);
                                        flag=0;
                                        
                                    }else{
                                        
                                        if(outstack(s[i])>instack(Stack.top()))
                                        {
                                           
                                            Stack.push(s[i]);
                                            flag=0;
                                        }
                                        
                                        else if(outstack(s[i])<instack(Stack.top()))
                                        {
                                          
                                            result=result+Stack.top();
                                            Stack.pop();
                                           
                                            
                                        }
                                        else if(outstack(s[i])==instack(Stack.top()))
                                        {
                                            
                                            Stack.pop();
                                            flag=0;
                                        }
                                        
                                    }
                                    
        
                      
                    }
                
            }
            else
            {
                
                result=result+s[i];
                
            }
        
 
            

        
    }
    
    
    while(!Stack.empty()){
        
        result+=Stack.top();
        Stack.pop();
    }
    
    return result;
}



int Evaluate(string s){
    
    int sum=0;
    stack<int> Stack;
    
    for(int i=0;i<s.length();i++){
        
        if(isOperandOrOperator(s[i])==1){
            
            int a=Stack.top();
            Stack.pop();
            
            int b=Stack.top();
            Stack.pop();
            
          
            
            
            
            if(s[i]=='+'){
                sum=a+b;
            }else if(s[i]=='-'){
                sum=b-a;
            }else if(s[i]=='*'){
                sum=a*b;
            }else if(s[i]=='/')
                sum=b/a;
            else if(s[i]=='%')
                sum=b%a;
            

            
            Stack.push(sum);
            
            
        }else{
            
            int c=s[i];
            c=c-48;
            Stack.push(c);
            
        
         
        }
    }
    
    
    
    return Stack.top();
}









int main() {
    
    string s="(98765432+10+12)-(23*12/24)";
    
    cout<<infixToPostfix(s)<<endl;
    

    
}
