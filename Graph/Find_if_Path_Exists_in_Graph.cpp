#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    
    unordered_map<int ,vector<int>> adj;
    for(int i = 0 ; i < edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool> visited;

    queue<int> q;
    q.push(source);
    visited[source] = true;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto i:adj[front]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
    

    return visited[destination];
}
int main(){
    // n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    cout<<validPath(3,edges,0,2);
}