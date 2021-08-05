//
//  main.cpp
//  BishuAndHisGirlFriend
//
//  Created by princeraj on 02/05/21.
//


/*
 
 
 
 Problem
 There are N countries {1,2,3,4....N} and N-1 roads(i.e depicting a tree)

 Bishu lives in the Country 1 so this can be considered as the root of the tree.

 Now there are Q girls who lives in various countries (not equal to 1) .

 All of them want to propose Bishu.But Bishu has some condition.

 He will accept the proposal of the girl who lives at minimum distance from his country.

 Now the distance between two countries is the number of roads between them.

 If two or more girls are at the same minimum distance then he will accept the proposal of the girl who lives in a country with minimum id.

 No two girls are at same country.

 Input: First line consists of N,i.e number of countries Next N-1 lines follow the type u v which denotes there is a road between u and v. Next line consists of Q Next Q lines consists of x where the girls live.

 Output: Print the id of the country of the girl who will be accepted.

 Help Him!!!!!

 contraints: 2<=N<=1000 1<=u,v<=N 1<=Q<=(N-1)

 Sample Input
 6
 1 2
 1 3
 1 4
 2 5
 2 6
 4
 5
 6
 3
 4
 Sample Output
 3
 Time Limit: 1
 Memory Limit: 256
 Source Limit:
 
 */

#include <iostream>
#include <vector>
using  namespace::std;



// array of vectors
vector<int> arr[1000];

//visited array
int visited[1000]={0};

//distance array
int dist[1000]={0};








void DFS(int node,int distance){
    
    
    if(visited[node]==0){
        
        visited[node]=1;
        dist[node]=distance;
        
        for(int child:arr[node])
            DFS(child, dist[node]+1);
        
    
    }
    
    
    
    
    
    
}





int main() {

    int GIRL_MAX=INT_MAX;
    
    int min_dist=INT_MAX;
    //N is no. of countries
    int N;
    cin>>N;
    
    vector<int> girls;
    
    int u,v;
    
    
    //adjacency list ready for tree/graph
    for(int i=1;i<=N-1;i++){
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
        
    }
    
    int Q;
    cin>>Q;
    int girl;
    
   
    
    for(int i=1;i<=N;i++){
        
        DFS(1,0);
        
    }
    
   
    
    for(int j=1;j<=Q;j++){
        cin>>girl;
        if(dist[girl]<=min_dist && girl<=GIRL_MAX){
            
            min_dist=dist[girl];
            GIRL_MAX=girl;
            
        }
        
    }
    
      
  
    
    
    cout<<GIRL_MAX<<endl;
    
    
    
    
    
  
    
    
    
    
   
    
 
   

    
}
