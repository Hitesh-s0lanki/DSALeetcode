#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

void dfs(int source,int des,unordered_map<int,list<int>> adj,vector<vector<int>> &ans,vector<int> temp){
    temp.push_back(source);
    if(source == des){
        ans.push_back(temp);
        temp.pop_back();
        return;
    }

    for(auto i:adj[source]){
            dfs(i,des,adj,ans,temp);
    }
    temp.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    unordered_map<int,list<int>> adj;
    int node = 0;
    for(auto i : graph){
        for(auto j:i)
            adj[node].push_back(j);
        node++;
    }

    vector<vector<int>> ans;
    vector<int> temp;
    dfs(0,graph.size()-1,adj,ans,temp);

    return ans;
}

int main(){
    vector<vector<int>> graph = {{1,2},{3},{3},{}};
    vector<vector<int>> ans = allPathsSourceTarget(graph);

    for(auto i:ans){
        for(auto j:i){
            cout<<j<<"\t";
        }
        cout<<endl;
    }
}