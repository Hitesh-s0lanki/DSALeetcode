#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;



vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    unordered_map<int,set<int> > adj;
    for(auto i:edges){
        int u = i[0];
        int v = i[1];
        if(adj[u].size() != 0){
            
        }
        adj[v].insert(u);
    }
    
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        vector<int> temp;

        for(auto j : adj[i]){   
            for(auto k:adj[j])
                adj[i].insert(k);
        }
        for(auto j: adj[i])
            temp.push_back(j);
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    //  n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
    vector<vector<int>> edge ={{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};
    int n = 8; 
    vector<vector<int>> ans = getAncestors(n,edge);
    for(auto i:ans){
        for(auto j:i)
            cout<<j<<'\t';
        cout<<endl;
    }
}