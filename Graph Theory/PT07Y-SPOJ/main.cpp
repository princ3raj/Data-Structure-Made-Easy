//
//  main.cpp
//  PT07Y-SPOJ
//
//  Created by princeraj on 02/05/21.
//


/*
 
 PT07Y - Is it a tree
 #dfs

 You are given an unweighted, undirected graph. Write a program to check if it's a tree topology.

 Input

 The first line of the input file contains two integers N and M --- number of nodes and number of edges in the graph (0 < N <= 10000, 0 <= M <= 20000). Next M lines contain M edges of that graph --- Each line contains a pair (u, v) means there is an edge between node u and node v (1 <= u,v <= N).

 Output

 Print YES if the given graph is a tree, otherwise print NO.

 Example

 Input:
 3 2
 1 2
 2 3

 Output:
 YES
 
 */



#include<vector>
#include <iostream>
using namespace std;





vector<int> arr[10001];
int visited[1001];


int DFS(int Node){
    
    if(visited[Node]==0){
        visited[Node]=1;
        for(int child:arr[Node])
            DFS(child);
    }
    return 0;
   
}







int main() {
    
    int count=-1;
    int N,M,u,v;
    cin>>N>>M;
    
    for(int i=1;i<=M;i++){
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    int result;
    
    for(int i=1;i<=N;i++){
        if(visited[i]==0){
            result=DFS(i);
            count++;
        }

    }
    
    
    if(count==1 && M==N-1){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    
    
    
    
    
    
    
    
    

}
