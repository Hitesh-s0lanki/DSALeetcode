#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;


vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g){
    
    unordered_map<int,list<pair<int,int>>> adj;
    for(auto i:g){
        int u = i.first.first; 
        int v = i.first.second;
        int w = i.second;

        adj[u].push_back(make_pair(v,w)); 
        adj[v].push_back(make_pair(u,w)); 
    }

    //Dist array
    vector<int> key(n+1,INT_MAX);
    vector<int> parent(n+1,-1);
    vector<bool> mst(n+1,-1);

    key[1] = 0;
    parent[1] = -1;

    for(int i = 1;i < n ;i++){
        int mini = INT_MAX;
        int u;

        //Find the MiniMum
        
    }
}

int main(){
    vector<pair<pair<int,int>,int>> edges = {make_pair(make_pair(1,2),2),make_pair(make_pair(1,4),6),make_pair(make_pair(2,1),2),make_pair(make_pair(1,2),2)};
}
