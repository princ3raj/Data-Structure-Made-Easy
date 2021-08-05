//
//  main.cpp
//  ReverseQueueWithQueueAdtOnly
//
//  Created by princeraj on 05/08/21.
//

/*
 Problem-1  Give an algorithm for reversing a queue Q. To access the queue, we are only
 allowed to use the methods of queue ADT.
 
 Time Complexity: O(n).
 */

#include <iostream>
#include<queue>
using namespace std;
queue<int> q;


void reverseQueue(){
    
    if(q.empty()) return;
    int temp=q.front();
    q.pop();
    reverseQueue();
    q.push(temp);
}

int main() {
    
    for(int i=1;i<=10;i++) q.push(i);
    reverseQueue();
    
    for(int i=1;i<=10;i++)
        cout<<q.front()<<" ",     q.pop();
    
    cout<<endl;
    
}
