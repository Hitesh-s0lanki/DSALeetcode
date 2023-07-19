#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//important book mai solution hai agar ni ave toh

bool compare(vector<int> &a,vector<int> &b){
    return a[2] < b[2];
}

void makeSet(vector<int> &parent,vector<int> &rank,int n){
    for(int i=0;i<n;i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent,int node){
    if(parent[node] == node){
        return node;
    }

    return parent[node] = findParent(parent,parent[node]);
}

void unionSet(int u,int v,vector<int> &parent,vector<int> &rank){
    u = findParent(parent,u);
    v = findParent(parent,v);

    if(rank[u]<rank[v]){
        parent[u] = v;
    }
    else if(rank[u] > rank[v]){
       parent[v] = u; 
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n){
    sort(edges.begin(),edges.end(),compare);


    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent,rank,n);

    int minWeight = 0;

    for(auto i:edges){
        int u =findParent(parent ,i[0]);
        int v = findParent(parent ,i[1]);
        int w = i[2];

        if(u != v){
            minWeight+=w;
            unionSet(u,v,parent,rank);
        }
    }
    return minWeight;
}

int main(){
//     0 1 3
// 0 3 5
// 1 2 1
// 2 3 8
    vector<vector<int>> edges = {{0,1,3},{0,3,5},{1,2,1},{2,3,8}};
    minimumSpanningTree(edges,4);
}