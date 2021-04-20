//
//  main.cpp
//  BFS-DFS
//
//  Created by princeraj on 19/04/21.
//


int visited[]={0,0,0,0,0,0,0};


int arr[7][7]={
    
    
    {0,1,1,1,0,0,0},
    {1,0,1,0,0,0,0},
    {0,1,0,1,1,0,0},
    {1,0,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0}

};

#include <iostream>
using namespace std;

//
//
//void DFS(int u){
//
//
//    if(visited[u]==0){
//
//        cout<<u<<endl;
//        visited[u]=1;
//
//
//        for(int v=0;v<7;v++){
//
//            if(arr[u][v]==1){
//                DFS(v);
//            }
//        }
//    }
//
//
//
//
//
//
//}


void DFS(int G[][7],int start,int n)
{
    static int visited[7]={0};
    int j;
    
    if(visited[start]==0)
    {
        printf("%d\n",start);
        visited[start]=1;
            
        for(j=0;j<n;j++)
            {
            if(G[start][j]==1 && visited[j]==0)
            DFS(G,j,n);
            }
    }
}


int main(int argc, const char * argv[]) {
    
    
    DFS(arr,0,7);
    
   
}
