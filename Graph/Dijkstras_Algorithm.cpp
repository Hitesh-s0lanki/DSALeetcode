#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<climits>
#include<queue>

using namespace std;

class compare{
    public:
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.first > b.first;
    }
};


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    unordered_map<int,list<pair<int,int>>> adj; 
    for(auto i:vec){
        int u = i[0];
        int v = i[1];
        int w = i[2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    //Distance array
    vector<int> dist(vertices);
    for(int i=0;i<vertices;i++)
        dist[i] = INT_MAX;

    //making source node = 0
    dist[source] = 0;

    //Created min heap to get smaller value agin and again in dist array
    //pair<dist,node>
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> minheap;
    minheap.push(make_pair(source,0));

    while(!minheap.empty()){

        pair<int,int> top = minheap.top();
        minheap.pop();
        cout<<top.first<<"\t"<<top.second<<endl;
        for(auto i:adj[top.second]){
            if(top.first + i.second < dist[i.first]){
                // change
                dist[i.first] = top.first + i.second;
                minheap.push(make_pair(dist[i.first],i.first));
            }
        }
    }

    return dist;

}
// <code>Input: 4 5      </code>
int main(){
    vector<vector<int>> edges = {{0,1,5},{0,2,8},{1,2,9},{1,3,2},{2,3,6}};
    vector<int> ans = dijkstra(edges,4,5,0);
    for(auto i:ans)
        cout<<i<<"\t";
}