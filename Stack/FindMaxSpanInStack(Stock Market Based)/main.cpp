//
//  main.cpp
//  FindMaxSpanInStack(Stock Market Based)
//
//  Created by princeraj on 19/07/21.
//

/*
 
 
 Problem-22  Finding Spans: Given an array A, the span S[i] of A[i] is the maximum number of consecutive elements A[j] immediately preceding A[i] and such that A[j] < A[i]?
 Other way of asking: Given an array A of integers, find the maximum of j – i subjected to the constraint of A[i] < A[j].
 
 
 Problem-23  Can we improve the complexity of Problem-22?
 Solution: From the example above, we can see that span S[i] on day i can be easily calculated if we know the closest day preceding i, such that the price is greater on that day than the price on day i. Let us call such a day as P. If such a day exists then the span is now defined as S[i] = i – P.
 
 
 
 12 13 11 10 6 3 2 7 3 33 56 68 101 17 3 6 5 7 1 2 3
 */

#include <iostream>
#include <stack>
using namespace std;

stack<int> s;


//MY APPROACH O(n^2)
void FindMaxSpan(int arr[],int n, int S[]){
    
    int count=1; S[0]=1;
    
    for(int i=1;i<n;i++){
                    for(int j=i-1;j>=0;j--)
                    {
                        if(arr[j]<arr[i]){
                            count++;
                        }else{
                            break;
                        }
                      
                    }
                 S[i]=count;
                 count=1;
        
        
                    
          
        
    }
    
    
    
    
}


void FindMaxSpanLinearTime(int arr[],int n,int Aux[]){
    
    
    int P;
   
    s.push(0);
    Aux[0]=1;
    for(int i=1;i<n;i++){
        while(!s.empty() && arr[s.top()]<=arr[i])
            s.pop();
        
        if(s.empty())
            Aux[i]=i+1;
        else
            P=s.top(),  Aux[i]=i-P;
        s.push(i);
        
        
    }
    
    
    
}







int main() {
    
    
    int n;
    cin>>n;
    int arr[n],S[n],Aux[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    
    FindMaxSpan(arr, n, S);
    for(int i=0;i<n;i++)
    {
        cout<<S[i]<<" ";
    }

    cout<<endl;
    
    FindMaxSpanLinearTime(arr, n, Aux);
    for(int i=0;i<n;i++)
    cout<<Aux[i]<<" ";
    
    cout<<endl;
    
    
  
}
