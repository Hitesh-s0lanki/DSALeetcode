#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

class compare{
    public:
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.first > b.first;
    }
};

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g){
    
    unordered_map<int,list<pair<int,int>>> adj;
    for(auto i:g){
        int u = i.first.first; 
        int v = i.first.second;
        int w = i.second;

        adj[u].push_back(make_pair(v,w)); 
        adj[v].push_back(make_pair(u,w)); 
    }
    //Key node pair<value,node> 
    vector<int> key(n+1);
    //mst of each node
    unordered_map<int,bool> mst; 
    //maping the parent of node
    unordered_map<int,int> parent;
    for(int i=1;i<= n ;i++){
        key[i]=INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    key[1] = 0;

    for(int i = 1;i <= n ;i++){
        //find the minimun
        int minimun = INT_MAX;
        for(int i = 1;i<= n;i++){
            if(key[i] < minimun && !mst[i]){
                // cout<<key[i]<<"\t"<<minimun<<endl;
                minimun = i;
            }
        }
        mst[minimun] = true;

        for(auto i:adj[minimun]){
            if(key[i.first] > i.second){
                parent[i.first] = minimun;
                key[i.first] = i.second;
            }
        } 
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2;i<= n ;i++){
        ans.push_back({{parent[i],i},key[i]});
    }

    return ans;
}

int main(){
    vector<pair<pair<int,int>,int>> edges = {make_pair(make_pair(1,2),5),make_pair(make_pair(1,3),8),make_pair(make_pair(2,3),10),make_pair(make_pair(2,4),15),make_pair(make_pair(3,4),20)};
    calculatePrimsMST(4,5,edges);
}
