//
//  main.cpp
//  StackGrowsOrDown
//
//  Created by princeraj on 19/07/21.
//

#include <iostream>
#include <stack>
using namespace std;



void stackGrowth(int *temp){
    
    
    int temp2=1;
    cout<<"Address of 1st Local Variable"<<temp<<endl;
    cout<<"Address of 2nd Local Variable"<<&temp2<<endl;
    if(temp<&temp2) cout<<"Stack is growing downwards"<<endl;
    else cout<<"Stack is growing upwards"<<endl;
    
}


int testStackGrowth(){
    
    int temporary=1;
    stackGrowth(&temporary);
    exit(0);

}





int main() {
    
    
    testStackGrowth();
  
}
