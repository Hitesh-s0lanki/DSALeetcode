#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool dfs(vector<int> adj[],unordered_map<int,bool> &visited,int index){
    visited[index] = true;
    for(int i= 0;i<2 && i<adj[index].size();i++){
        if(!visited[adj[index][i]]){
            bool ans = dfs(adj,visited,adj[index][i]);
            if(!ans){
                return false;
            }
        }
        else{
            return false;
        }
    }
    return true;
}

bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(leftChild[i] != -1)
                adj[i].push_back(leftChild[i]);
            if(rightChild[i] != -1)
                adj[i].push_back(rightChild[i]);
        }
        

        //dfs Transversal
        unordered_map<int,bool> visited;

        bool ans = dfs(adj,visited,0);
        if(!ans)
            return false;

        for(int i=0;i<n;i++){
            if(adj[i].size() > 2 || !visited[i]){
                return false;
            }
        }

        return true;
    }
int main(){
    vector<int> left ={1,-1,3,-1};
    vector<int> right ={2,-1,-1,-1};
    cout<<validateBinaryTreeNodes(4,left,right);
}