#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<stack>
#include<climits>

using namespace std;

class Graph{
    public:
    unordered_map<int,list<pair<int,int>> > adj;
    
    void addEdge(int u,int v,int weight){
        pair<int,int> p(v,weight);
        adj[u].push_back(p);
    }
    void print(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<") "<<" , "; 
            }
            cout<<endl;
        }
    }
    void dfs(int node,unordered_map<int,bool> &visited,stack<int> &topo){
        visited[node] = true;
        for(auto i:adj[node]){
            if(!visited[i.first]){
                dfs(i.first,visited,topo);
            }
        }
        topo.push(node);
    }
    stack<int> topoSort(){
        stack<int> topo;

        unordered_map<int,bool> visited;

        for(auto i:adj){
            if(!visited[i.first]){
                dfs(i.first,visited,topo);
            }
        }

        return topo;
    }
    void printStack(stack<int> topo){
        while(!topo.empty()){
            cout<<topo.top()<<"\t";
            topo.pop();
        }
        cout<<endl;
    }
    void shortestDistance(int src,vector<int> &dist,stack<int> &topo){
        dist[src] = 0;
        while(!topo.empty()){
            int top = topo.top();
            topo.pop();

            if(dist[top] != INT_MAX){
                for(auto i:adj[top]){
                    if(dist[top]+ i.second < dist[i.first]){
                        dist[i.first] = dist[top]+ i.second ;
                    }
                }
            }
        }
    }
    void printVector(vector<int> temp){
        for(auto i:temp)
            cout<<i<<"\t";
    }
};

int main(){
    
    Graph G; // Graph G

    

    // add all edges to graph

    G.addEdge(1, 3, 6);
    G.addEdge(1, 2, 2);
    G.addEdge(0, 1, 5);
    G.addEdge(0, 2, 3);
    G.addEdge(3, 4, -1);
    G.addEdge(2, 4, 4);
    G.addEdge(2, 5, 2);
    G.addEdge(2, 3, 7);
    G.addEdge(4, 5, -2);

    G.print();

    stack<int> topo = G.topoSort();
    G.printStack(topo);

    int n =6;
    vector<int> dist(n);
    for(int i= 0;i<n;i++)
        dist[i] = INT_MAX;

    G.shortestDistance(1,dist,topo);
    G.printVector(dist);
}