#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

bool solveBFS(unordered_map<int,list<int> > adj,unordered_map<int , bool> &visited,int node){
    unordered_map<int , int >  parent;

    parent[node] = -1;

    queue<int> q;
    q.push(node);
    visited[node] = true;
    while(!q.empty()){
        int valP = q.front();
        q.pop();
        for(auto i:adj[valP]){
            if(visited[i] && i != parent[valP]){
                return true;
            }
            else if(!visited[i]){
                q.push(i);
                parent[i] = valP;
                visited[i] = true;
            }
        }
    }
    return false;
}


bool solveDFS(unordered_map<int,list<int> > adj,unordered_map<int , bool> &visited,int node,int parent){

    visited[node] = true;

    for(auto i: adj[node]){
        if(!visited[i]){
            bool ans = solveDFS(adj,visited,i,node);
            if(ans)
                return true;
        }
        else if(i != parent){
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m){
    // Write your code here.
    unordered_map<int,list<int> > adj;
    for(int i=0;i< m ;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    unordered_map<int , bool> visited;

    //For all Node
    for(int i = 0 ;i < n ; i++){
        if(!visited[i]){
            // bool ans = solveBFS(adj,visited,i);
            bool ans = solveDFS(adj,visited,i,-1);
            if(ans)
                return "Yes";
        }
    }
    return "No";
}
int main(){
    vector<vector<int> > edge = {{1,2},{2,3},{4,5},{5,6},{5,7},{7,8},{6,8},{8,9}};
    cout<< cycleDetection(edge,9,8);
}