//
//  main.cpp
//  BugLife
//
//  Created by princeraj on 04/05/21.
//

#include <iostream>
#include <vector>

using  namespace::std;


vector<int> arr[2000];
int visited[2000];
int color[2000];

vector<int> answers;


bool BugsFoundOrNot(int node, int col){
    
    
    visited[node]=1;
    color[node]=col;
    
    for(int child:arr[node]){
        
        if(visited[child]==0){
            
            if(BugsFoundOrNot(child, col^1)==false)
                return false;
            
        }else{
            if(color[node]==color[child]){
                return false;
                
            }
        }
        
    }
    
    return true;
}



int main() {
    
    
    int scenario;
    cin>>scenario;
    int loop=scenario;
    int no_of_bugs, no_of_interactions;
    int u,v;
    
    while(scenario){
        cin>>no_of_bugs>>no_of_interactions;
        
        for(int i=1;i<=no_of_interactions;i++){
            cin>>u>>v;
            arr[u].push_back(v);
            arr[v].push_back(u);

        }
        
        
        
        
        answers.push_back(BugsFoundOrNot(1, 0));
        
        for(int j=1;j<=no_of_interactions;j++){
            
            arr[j].clear();
            
        }
        
        
        
        
        scenario--;
    }
    
    int j=1;
    for(int i=0;i<loop;i++){
        cout<<"Scenario #"<<j+i<<":"<<endl;
        if(answers[i]){
            cout<<"No suspicious bugs found!"<<endl;
        }else{
            cout<<"Suspicious bugs found!"<<endl;
            
        }
        
    }

}
