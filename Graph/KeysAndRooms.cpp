#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();

    vector<bool> visited(n,false);

    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int element = q.front();
        q.pop();
    
        visited[element] = true;
        for(auto i:rooms[element]){
            if(!visited[i]){
                q.push(i);
            }
        } 
    }
    for(auto i:visited){
        if(i == false)
            return false;
    }
    
    return true;
}
int main(){
    vector<vector<int>> rooms = {{1,3},{3,0,1},{2},{0}};

    cout<<canVisitAllRooms(rooms);
}