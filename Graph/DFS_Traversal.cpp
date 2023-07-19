#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

void dfs(int node , unordered_map<int ,list<int> > adj, unordered_map<int,bool> &visited,vector<int> &temp){
    temp.push_back(node);
    visited[node] = true;

    for(auto i : adj[node]){
        if(!visited[i]){
            dfs(i,adj,visited,temp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges){
    
    unordered_map<int,list<int>> adj;
    for(int i = 0; i < E ;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    } 

    unordered_map<int,bool> visited;

    vector<vector<int> > ans;
    for(int i = 0 ; i < V ;i++){
        if(!visited[i]){
            vector<int> temp;
            dfs(i,adj,visited,temp);
            ans.push_back(temp);
        }
    }
    return ans;
}
int main(){
// 5 4
    vector<vector<int>> val = {{0,2},{0,1},{1,2},{3,4}};
    
    vector<vector<int>> ans = depthFirstSearch(5,4,val);

    for(auto i: ans){
        for(auto j: i){
            cout<<j<<"\t";
        }
        cout<<endl;
    }
}