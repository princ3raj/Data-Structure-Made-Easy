//
//  main.cpp
//  DFS
//
//  Created by princeraj on 01/05/21.
//


/*
 
 Problem
 Given n, i.e. total number of nodes in an undirected graph numbered from 1 to n and an integer e, i.e. total number of edges in the graph. Calculate the total number of connected components in the graph. A connected component is a set of vertices in a graph that are linked to each other by paths.

 Input Format:

 First line of input line contains two integers n and e. Next e line will contain two integers u and v meaning that node u and node v are connected to each other in undirected fashion.

 Output Format:

 For each input graph print an integer x denoting total number of connected components.

 Constraints:

 All the input values are well with in the integer range.

 Sample Input
 8 5
 1 2
 2 3
 2 4
 3 5
 6 7
 Sample Output
 3
 Time Limit: 5
 
 */

#include <iostream>
using namespace std;





int visited[10000]={0};

struct Node {
    
    int data;
    Node *next;
    
};


Node *arr[10000]={NULL};




void AdjacencyList(int Nodes,int Edges){
    
    if(arr[Nodes]==NULL){
        
        Node *p=new Node;
        p->data=Edges;
        p->next=NULL;
        arr[Nodes]=p;
        
    }else{
        
        
        Node *q=arr[Nodes];
        while(q->next){
            q=q->next;
            
        }
        
        Node *p=new Node;
        p->data=Edges;
        p->next=NULL;
        q->next=p;
        
    }
    
    
}


void DFS(int Nodes){
   

    Node *p= arr[Nodes];

        
        if(visited[Nodes]==0){
            visited[Nodes]=1;
            while(p){
                DFS(p->data);
                p=p->next;
            }
        }
   
    return;
}






int main() {
    
    int count=0;
    int n,m;
    cin>>n>>m;
    
    int u,v;
    while(m){
        cin>>u>>v;
        AdjacencyList(u, v);
        m--;
    }

   
    
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            DFS(i);
            count++;
            
        }
  
    }
    
    
    cout<<count<<endl;
 
   
    
}
