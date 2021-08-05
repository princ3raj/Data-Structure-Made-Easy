//
//  main.cpp
//  BipartiteTest
//
//  Created by princeraj on 02/05/21.
//
// C++ program to check if a connected
// graph is bipartite or not suing DFS
#include <iostream>
#include <vector>
using namespace std;



vector<int> arr[1001];
int visited[1001];
vector<int> color(1001,NULL);



bool BipartiteTest(int node, int col){
    
    
    visited[node]=1;
    color[node]=col;
    
    
    for(int child:arr[node]){
        
        if(visited[child]==0){
            if(BipartiteTest(child, col^1)==false)
                return false;
            
        }
        else{
            if(color[node]==color[child])
                return false;
            
        }
    }
    return true;
}






int main(){
    
    
    int M,u,v;
    
    cout<<"Enter M edges"<<endl;
    cin>>M;
    
    for(int i=1;i<=M;i++){
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    
    
    if(BipartiteTest(1, 0)){
        cout<<"Bipartite"<<endl;
        
    }else{
        cout<<"Not a Bipartite"<<endl;
    }
    
    
    
    
    
    
}
