#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;

bool detectCycleInDirectedGraphDfs(unordered_map<int ,list<int>> adj,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfs,int node){
    visited[node] = true;
    dfs[node] = true;
    for(auto i: adj[node]){
        if(!visited[i]){
            bool ans = detectCycleInDirectedGraphDfs(adj,visited,dfs,i);
            if(ans)
                return 1;
        }
        else if(visited[i] && dfs[i]){
            return 1;
        }
    }
    dfs[node] = false;
    return 0;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int ,list<int>> adj;
  for(auto i:edges){
    int u = i.first;
    int v = i.second;

    adj[u].push_back(v);
  }

  unordered_map<int,bool> visited;
  unordered_map<int,bool> dfs;

  for(int i = 1;i<=n ;i++){
    if(!visited[i]){
        bool ans = detectCycleInDirectedGraphDfs(adj,visited,dfs,i);
            if(ans)
                return 1;
    }
  }
  return 0;
}
int main(){
    vector<pair<int,int>> edges ={make_pair(1,2),make_pair(2,3),make_pair(2,4),make_pair(3,7),make_pair(3,8),make_pair(8,7),make_pair(4,5),make_pair(5,6),make_pair(6,4)};
    cout<<detectCycleInDirectedGraph(8,edges);
}