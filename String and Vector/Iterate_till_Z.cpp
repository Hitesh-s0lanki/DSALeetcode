#include<iostream>
#include<vector>
using namespace std;

vector<int> iterateTillZ(int x, int y, int z) {
    vector<int> ans;
    for(int i = 1; i <= z; i++ ){
        if(i%x == y){
            ans.push_back(i);
        } 
    }
    return ans;
}

int main(){
    vector<int> ans = iterateTillZ(3,2,10);
    for(auto val : ans){
        cout<<val<<"\t";
    }
}