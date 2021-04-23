//
//  main.cpp
//  A-StarAlgorithm
//
//  Created by princeraj on 20/04/21.
//


const int M=5;
const int N=5;



static int rowNbr[] = {  -1,  0, 0,  1  };
static int colNbr[] = {   0,  -1, 1, 0 };

#include <iostream>
using namespace std;


bool isSafe(int Row, int Column, int visited[M][N]){
    
    if((Row>=0 && Column >=0)&& visited[Row][Column]==1){
        return true;
    }else{
        return false;
    }
    
    
    
}


void traverseGraph(int arr[M][N],int i, int j, int m, int n, int visited[M][N]){
    
    int prev_i=i;
    int prev_j=j;
    int increment=0;
    
    while(i!=m && j!=n){
        
            i=i+rowNbr[increment];
            j=j+colNbr[increment];
        
        if(isSafe(i, j,visited)&&arr[i][j]!=1){
            
            int max=999;
            
            if(max>i+j){
                max=i+j;
            }
            increment++;
            int store[100];
            
            store[max]=i;
            store[max+1]=j;
        
            prev_i=i;
            prev_j=j;
            visited[i][j]=0;
           
            
            cout<<store[max]<<","<<store[max+1];
            traverseGraph(arr, i, j, m, n, visited);
            
            
        
                    
        }
        
        
        else{
            
            i=prev_i;
            j=prev_j;
            
            if(increment<8){
                increment++;
            }else{
                increment=0;
            }
            
            
            
        }
        
        
        
        
        
    }
   
}





int main() {
    
    
    int arr[M][N]={
        
        {0,0,0,0,0},
        {0,1,1,1,0},
        {0,0,0,0,0},
        {1,0,1,1,1},
        {0,0,0,0,0}
    };
    
    int visited[M][N]={
        
        
        {1,1,1,1,1},
        {1,1,1,1,1},
        {1,1,1,1,1},
        {1,1,1,1,1},
        {1,1,1,1,1}
    };
    
    visited[0][1]=0;
    
    traverseGraph(arr,0,1,4,3,visited);
    
   
}
