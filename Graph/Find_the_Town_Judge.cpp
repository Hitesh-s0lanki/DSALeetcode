#include<iostream>
#include<vector>
using namespace std;


//Submit ne vaetu
int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> adj[n+1];
    for(int  i = 0; i < trust.size() ;i++){
        int u = trust[i][0];
        int v = trust[i][1];

        adj[u].push_back(v);
    }
    for(int i =1;i<=n;i++){
        if(adj[i].size() == 0)
            return i;
    }
    return -1;
}
int main(){
    vector<vector<int>> trust = {{1,2}};
    cout<<findJudge(2,trust);
}