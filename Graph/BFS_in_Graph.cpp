#include<iostream>
#include<set>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

void print(unordered_map<int,set<int> > adj){
    for(auto i:adj){
        cout<<i.first<<" -> ";
        for(auto j: i.second)
            cout<<j<<"\t";
        cout<<endl;
    }
}

void solve(unordered_map<int,set<int> > adj,unordered_map<int , bool > &visited,vector<int> &ans,int n){

    queue<int> q;
    q.push(n);

    visited[n] = true;
    while(!q.empty()){
        int val = q.front();
        q.pop();
        ans.push_back(val);
        
            for(auto i : adj[val]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
    }
}


vector<int> BFS(int vertex, vector<pair<int, int>> edges){
    
    unordered_map<int,set<int> > adj;

    for(auto i:edges){
        int u = i.first;
        int v = i.second;

        adj[u].insert(v); 
        adj[v].insert(u); 
    }
    
    vector<int> ans;

    unordered_map<int , bool > visited;
    for(int i = 0;i < vertex; i++){
        if(!visited[i]){
            solve(adj,visited,ans,i);
        }
    } 

    return ans;
}
int main(){
    vector<pair<int, int>> edges = {make_pair(0,1),make_pair(0,3),make_pair(1,3)};
    
    vector<int> ans = BFS(4,edges);
    for(auto i:ans)
        cout<<i<<"\t";
}