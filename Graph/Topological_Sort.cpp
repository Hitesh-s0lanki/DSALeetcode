#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
using namespace std;

void dfs(int node,vector<int> adj[],vector<bool> &visited,stack<int> &s){
    
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i,adj,visited,s);
        }
    }
    s.push(node);
}


// vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
//     // Write your code here
//     vector<int> adj[v];
//     for(int i =0;i<e;i++){
//         int u = edges[i][0];
//         int v = edges[i][1];

//         adj[u].push_back(v);
//     }

//     vector<bool> visited(v);
//     //Dfs Tranversal 

//     stack<int> s;

//     for(int i = 0 ;i < v ;i++){
//         if(!visited[i]){
//             dfs(i,adj,visited,s);
//         }
//     }
    
//     vector<int> ans;
//     while(!s.empty()){
//         ans.push_back(s.top());
//         s.pop();
//     }
//     return ans;
// }

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //Kahn's Algorithm
    // Write your code here
    vector<int> adj[v];
    for(int i =0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //indegree
    unordered_map<int,int> indegree;
    for(int i =0;i< v ;i++){
        for(auto j:adj[i])
            indegree[j]++;
    }


    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;
    // do bfs
    while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);
        
        for(auto i:adj[front]){
            indegree[i]--;
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    }
    return ans;
}



int main(){
    vector<vector<int>> edges = {{0,1},{0,3},{1,2},{3,2}};
    vector<int> ans = topologicalSort(edges,4,edges.size());
    for(auto i:ans)
        cout<<i<<"\t";
}
// 0       3       1       2