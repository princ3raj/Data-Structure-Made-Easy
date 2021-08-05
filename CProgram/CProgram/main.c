//
//  main.c
//  CProgram
//
//  Created by princeraj on 30/06/21.
//

#include <stdio.h>
#include <Python/Python.h>



int main() {
    Py_Initialize();
    PyRun_SimpleString("x = []; x.append('python'); x.append('invoked');x.append('using C'); print(x)");
    
    printf("Hi\n");
   
 
}
