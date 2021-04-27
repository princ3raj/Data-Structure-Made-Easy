//
//  main.cpp
//  HashFunctionUsingSubtractionMethod
//
//  Created by princeraj on 27/04/21.
//





#include <iostream>
using namespace std;



int HashFunction(int x){
    return x-2000;
}


void HashtableForEmployee(){
    
    cout<<"*******Hash table*********"<<endl;
    cout<<endl;
    cout<<"key"<<"    "<<"Address"<<endl;
    for(int i=2000;i<=2020;i++){
        cout<<i<<"    "<<HashFunction(i)<<" ";
        cout<<endl;
        
    }
    
    
    
    
    
    
}




int main() {
    
    
    cout<<"Press any key to generate Hashtable for employees"<<endl;
    getchar();
    HashtableForEmployee();
 
}
