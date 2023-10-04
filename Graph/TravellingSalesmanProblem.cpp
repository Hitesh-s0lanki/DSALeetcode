#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<climits>
using namespace std;

int dfs(vector<vector<vector<int>>> adj,vector<bool> visited,int node,int dis){
    visited[node] = true;
    
    int ans = INT_MAX;
    int count = 0;
    for(auto val:adj[node]){
        if(!visited[val[0]]){
            ans = min(ans,dfs(adj,visited,val[0],val[1]));
            count++;
        }
    }
    if(count == 0){
        for(auto val:adj[node]){
            if(val[0] == 0){
                ans = val[1]; 
            }
        }
    }
    int val = ans + dis;
    return val ;
}
int shortestRoute(vector<vector<int>> &distance){
    int n = distance.size();
    vector<vector<vector<int>>> adj(n);
    for(int i = 0;i < n;i++){
        for(int j = 0; j < n ; j++){
            if(j != i){
                adj[i].push_back({j,distance[i][j]});
            }
        }
    }

    for(int i = 0 ;i < n ; i++){
        cout<<i<<" -> ";
        for(auto j:adj[i]){
            cout<<"("<<j[0]<<","<<j[1]<<"),";
        }
        cout<<endl;
    }

    vector<bool> visited(n,false);
    visited[0] = true;
    int ans = INT_MAX; 
    for(auto node:adj[0]){
        ans = min(dfs(adj,visited,node[0],node[1]),ans);
    }
    if(ans == INT_MAX)
        return distance[0][0];
    return ans;
}
int main(){
    // vector<vector<int>> dis = {{0, 47},{47, 0}};
    vector<vector<int>> dis = {{0, 47, 19, 12},
    {47, 0, 35, 36},{19, 35, 0, 16},{12, 36, 16, 0}};
    cout<<shortestRoute(dis);
     
}