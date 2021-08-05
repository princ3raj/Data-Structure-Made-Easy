//
//  main.cpp
//  EvaluateInfixToPostfixInOnePassUsingTwoStack
//
//  Created by princeraj on 10/06/21.
//


/*
 
 this code only works for one's place digit
 now it works for more than one's place digit but still has some errors
 */
#include <sstream>
#include <iostream>
#include<stack>
using namespace std;





int number_converter(int num, int place){
    
    int number=0;
    
    
    
    
    
    
    return number;
    
}

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


int Evaluate(string s){
    string s1;
    string s2;
    long count=0;
    int reverse_flag=1;
    int reverse_flag_2=1;
    
    int flag=1;
    
    stack<int> Stack_opd;
    stack<char> Stack_opt;
    
    stack<long> Stack_count;
    
    
    if(isOperandOrOperator(s[0])){
    
        Stack_opt.push(s[0]);
    }else{
        Stack_opd.push(s[0]);
       
    }
    
    for(int i=1;i<s.length();i++){
        
       
        
        flag=1;
        
        
        if(isOperandOrOperator(s[i])){
            
           
            Stack_count.push(count);
            count=0;
          
            
                  
                        
                        while(flag==1){
                            
                            s1="";
                            s2="";
                            
                            
                            
                                        if(Stack_opt.empty()){
                                            
                                         
                                            Stack_opt.push(s[i]);
                                            flag=0;
                                            
                                        }else{
                                            
                                            if(outstack(s[i])>instack(Stack_opt.top()))
                                            {
                                               
                                                Stack_opt.push(s[i]);
                                                flag=0;
                                            }
                                            
                                            else if(outstack(s[i])<instack(Stack_opt.top()))
                                            {
                                              
                                                char c=Stack_opt.top();
                                                Stack_opt.pop();
                                                
                                            
                                                long loop_one,loop_two;
                                                
                                                loop_one=Stack_count.top();
                                                Stack_count.pop();
                                                loop_two=Stack_count.top();
                                                Stack_count.pop();
                                                
                                               
                                                for(int k=0;k<loop_one;k++){
                                               
                                                    string c1=to_string(Stack_opd.top());
                                                    
                                                    if(c1.length()>1){
                                                        reverse_flag=0;
                                                    }
                                                
                                                    Stack_opd.pop();
                                                    s1+=c1;
                                                }
                                                
                                                for(int l=0;l<loop_two;l++){
                                                    
                                                  
                                                    string c2=to_string(Stack_opd.top());
                                                    if(c2.length()>1){
                                                        reverse_flag_2=0;
                                                    }
                                                    Stack_opd.pop();
                                                    s2+=c2;
                                                    
                                                }
                                                
                                         
                                                
                                                if(reverse_flag){
                                                    reverse(s1.begin(),s1.end());
                                                }
                                                
                                                if (reverse_flag_2) {
                                                    reverse(s2.begin(),s2.end());
                                                }
                                              
                                                
                                         
                                                
                                                
                                                
                                               
                                                
                                                stringstream geek(s1);
                                                  int a = 0;
                                                  geek >> a;
                                                
                                                
                                             
                                                
                                                stringstream peek(s2);
                                                  int b = 0;
                                                  peek >> b;
                                                
                                             
                                    
                                                
                                                if(c=='+'){
                                                    Stack_opd.push(b+a);
//                                                    long length_of_string = to_string(b+a).length();
                                                    Stack_count.push(1);
                                                    
                                                }else if(c=='*'){
                                                    Stack_opd.push(b*a);
                                                    Stack_count.push(1);
                                                }else if(c=='-'){
                                                    Stack_opd.push(b-a);
                                                    
                                                    Stack_count.push(1);
                                                }else if(c=='/'){
                                                    Stack_opd.push(b/a);
                    
                                                    Stack_count.push(1);
                                                }else if(c=='%'){
                                                    Stack_opd.push(b%a);
                                                    Stack_count.push(1);
                                                }
                                               
                                                
                                            }
                                            else if(outstack(s[i])==instack(Stack_opt.top()))
                                            {
                                                
                                                Stack_opt.pop();
                                                flag=0;
                                            }
                                            
                                        }
                                        
            
                          
                        
                    }
            
            
          
            
        }
        else
        {
            count++;
            int sum=s[i];
            Stack_opd.push(sum-48);
        }
        
        

        
    }
    
    
//    while(!Stack_opt.empty()){
//
//
//        char sign=Stack_opt.top();
//        Stack_opt.pop();
//
//        int x,y;
//        x=Stack_opd.top();
//        Stack_opd.pop();
//        y=Stack_opd.top();
//        Stack_opd.pop();
//
//
//
//        if(sign=='+'){
//            Stack_opd.push(y+x);
//
//        }else if(sign=='*'){
//            Stack_opd.push(y*x);
//        }else if(sign=='-'){
//            Stack_opd.push(y-x);
//        }else if(sign=='/'){
//            Stack_opd.push(y/x);
//        }else if(sign=='%'){
//            Stack_opd.push(y%x);
//        }
//
//    }
    
    
  
    


    
    
    
    
    return Stack_opd.top();
    
}








int main() {

    
    string s="(134+2+4+10000/2)";

  
    cout<<Evaluate(s)<<endl;
    
    
    

}
