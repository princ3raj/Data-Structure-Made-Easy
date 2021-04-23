//
//  main.cpp
//  APSP
//
//  Created by princeraj on 18/04/21.
//

/*
 
 
 Warshall's algrithm is used for finding the Path matrix which gives us the all possible path from a given point.O(n^3)
 
 it's modified version is known as Dijkstra Algorithm, which is used for finding all pair shortest path (APSP) O(n^3)
 
 
 Warshall Algirithm, used here to find Path Matrix using Adjacency Matrix which I have intialized as a initial value of path matrix. since each edge represent a path to its adjacent component.
 
 
 
 What is Dijkstra Algorithm?(For weighted) this is dynamic programming approach
 
 This algorithm provides an easy solution to solve the problem
 of finding the shortest route b/w any two destination in a graph and also the shortest path from the given destination to all points in a graph.
 
 basically we try to find ,is there any intermediate node which helps us to reach from v[i] to v[j] in shortest way possible
 
 like v[i]->v[k]->v[j] <w v[i]->v[j]
 
 by keeping each vertex as an intermediate node and then looping over 'left (bach hua)' node to find the shortest way possible
 
 it's complexity is O(n^3) and used for small no. of input.
 
 
Note:-There is a greedy approach for finding shortest path
 
 Formula for APSP:-A[i][j]=min(A[i][j],A[i][k]+A[k][j])
 Formula for Path Matrix:- A[i][j] OR (A[i][k] AND A[k][j])
 
 
 
 */



const int M=4;
const int N=4;

 int INF=99999;


#include <iostream>
using namespace::std;




int  FindMinimum(int a, int b){
    
    if(a<=b){
        return a;
        
    }
    
    return b;
}


int OR(int a, int b){
    
    if(a || b){
        return 1;
    }else{
        return 0;
    }
    
}

int AND(int a, int b){
    
    if(a&&b){
        return 1;
    }else{
        return 0;
    }
    
    
}

void PrintMatrix(int arr[M][N]){
    
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    
    cout<<endl;
}

// it is also known as single source shortest path
void DijkstraAlgorithAPSP(int P[M][N]){
    
    
    for(int k=0;k<M;k++){
        for(int j=0;j<M;j++){
            for(int i=0;i<M;i++){
                
                
                P[i][j]=FindMinimum(P[i][j], P[i][k]+P[k][j]);

                
            }
        }
    }
    
    //Print the All Pair Shortest path
    PrintMatrix(P);
    
    
    
    
}



//Evaluate the Path Matrix using Warshall's Algorithm
void PathMatrix(int P[M][N]){
    
    
    
    for(int k=0;k<M;k++){
        for(int j=0;j<M;j++){
            for(int i=0;i<M;i++){
                
                P[i][j]=OR(AND(P[i][k],P[k][j]),P[i][j]);
                
                
                
            }
        }
    }
    //Print the Path Matrix
    PrintMatrix(P);
    
}





int main() {
    
    int A[M][N]={
        
        {0,0,0,1},
        {1,0,1,1},
        {1,0,0,1},
        {0,0,1,0}
    };
    
    int P[M][N]={
        {0,3,INF,7},
        {8,0,2,INF},
        {5,INF,0,1},
        {2,INF,INF,0}
    };
    
  
    
    PathMatrix(A);
    
    DijkstraAlgorithAPSP(P);
    
    
    
    
  
}
