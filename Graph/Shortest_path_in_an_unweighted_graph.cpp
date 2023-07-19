#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	vector<int> adj[n+1];
    for(auto i:edges){
        int u = i.first;
        int v = i.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //Visited node
    vector<bool> visited(n+1);

    unordered_map<int, int > parent;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto i:adj[front]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
                parent[i] = front;
            }
        }
    }

    //ans vector
    vector<int> ans;
    int curr = t;
    ans.push_back(t);
    while(curr != s){
        curr = parent[curr];
        ans.push_back(curr);
    }

    reverse(ans.begin(),ans.end());

    return ans;
}
int main(){
    vector<pair<int,int>> edges = {make_pair(2,5),make_pair(1,2),make_pair(1,3),make_pair(1,4),make_pair(5,8),make_pair(3,8),make_pair(4,6),make_pair(6,7),make_pair(7,8)};

    vector<int> ans = shortestPath(edges,8,9,1,8);
    
    for(auto i:ans){
        cout<<i<<"\t";
    }
}
