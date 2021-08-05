

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


#include "Header.h"
using namespace std;

vector<int> arr[100001];
int visited[100001];

void dfs(int node)
{
    visited[node] = 1;
    
    for(int child : arr[node])
    if(!visited[child])
    dfs(child);
    
}


int main()
{
    int n , m , a , b;
    cin>>n>>m;
    
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    
    
    int cc = 0;
    
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
            cc++;
        }
       
    }
   
    
    cout<<cc<<endl;
}
