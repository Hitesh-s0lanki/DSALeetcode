#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template <typename T>
class graph{
    public:
    unordered_map<T,list<T> > adj;

    void addEdge(T u,T v,bool direction){
        // connecting u -> v
        adj[u].push_back(v);
        if(!direction){
            adj[v].push_back(u);
        }
    }

    void print(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<j<<" , ";
            }
            cout<<endl;
        }
    }
};

int main(){
    graph<int> g1;
    g1.addEdge(1,2,false); 
    g1.addEdge(2,3,false); 
    g1.addEdge(3,1,false);  
    g1.print();
}