//
//  main.cpp
//  TowerOfHanoi
//
//  Created by princeraj on 17/04/21.
//

#include <iostream>
using namespace::std;


void TowerOfHanoi(int n, string source ,string destination, string helper){
    
    
    
    if(n==1){
        
        cout<<"Move disk 1 from "<<source<<" to "<<destination<<endl;
        
        return;
    }
    
    TowerOfHanoi(n-1,source , helper, destination);
    
    cout<<"Move disk "<<n<< " from "<<source<<" to "<<destination<<endl;
    
    TowerOfHanoi(n-1, helper, destination, source);
}

int main(int argc, const char * argv[]) {
    
    
    TowerOfHanoi(3, "A", "C", "B");
    
    
}
