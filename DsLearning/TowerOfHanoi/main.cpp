//
//  main.cpp
//  TowerOfHanoi
//
//  Created by princeraj on 17/04/21.
//

/*
 Problem-1 Discuss Towers of Hanoi puzzle.
 Solution: The Towers of Hanoi is a mathematical puzzle. It consists of three rods (or pegs or
 towers), and a number of disks of different sizes which can slide onto any rod. The puzzle starts
 with the disks on one rod in ascending order of size, the smallest at the top, thus making a conical
 shape. The objective of the puzzle is to move the entire stack to another rod, satisfying the
 following rules:
 • Only one disk may be moved at a time.
 • Each move consists of taking the upper disk from one of the rods and sliding it onto
 another rod, on top of the other disks that may already be present on that rod.
 • No disk may be placed on top of a smaller disk.
 
 
 input:-3
 
 output:- 3
 
 Move disk 1 from A to C
 Move disk 2 from A to B
 Move disk 1 from C to B
 Move disk 3 from A to C
 Move disk 1 from B to A
 Move disk 2 from B to C
 Move disk 1 from A to C
 
 
 */

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
    
    
    int n;
    cin>>n;
    
    TowerOfHanoi(n, "A", "C", "B");
    
    
}
