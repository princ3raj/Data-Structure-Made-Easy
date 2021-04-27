//
//  main.cpp
//  HashTable
//
//  Created by princeraj on 27/04/21.
//

#include "iostream"
#include "chains.h"
using namespace std;



int main() {
    

    HashTable hashtable;
    hashtable.insert(225);
    hashtable.insert(435);
    hashtable.insert(135);
    hashtable.insert(145);
    hashtable.insert(455);
    hashtable.insert(123);
    hashtable.insert(232);
    hashtable.insert(131);
    hashtable.insert(127);
    hashtable.insert(337);
    hashtable.insert(999);
    hashtable.insert(9);
    hashtable.insert(229);
    
    cout<<"******Before any Opeartions*****"<<endl;
    hashtable.Display();
    
    hashtable.Delete(9);
    hashtable.Delete(225);
    hashtable.Delete(135);
    hashtable.Delete(455);
    hashtable.Delete(125);
   
    hashtable.search(9999);
    hashtable.search(455);
    hashtable.search(337);
    
    cout<<"******After Opeartions*****"<<endl;
    hashtable.Display();
    

}
