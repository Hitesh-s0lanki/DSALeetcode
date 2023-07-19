#include<iostream>
#include<vector>
using namespace std;

int findCenter(vector<vector<int>>& edges) {
    int node = edges.size() + 1 ;
    vector<int> ans[node + 1];

    for(int i = 0 ; i < edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }
    int ansSize = 0;
    int maxi =0;
    for(int i = 1 ;i < node + 1;i++){
        if(ans[i].size() > ansSize){
            maxi = i;
            ansSize = ans[i].size();
        }
    }
    return maxi;
}
int main(){
    // [[1,2],[2,3],[4,2]]
    vector<vector<int>> edge={{1,2},{2,3},{4,2}};

    cout<<findCenter(edge);
}