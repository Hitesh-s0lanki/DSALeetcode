#include<iostream>
#include<vector>
using namespace std;

bool solve(vector<int> v, int n, int x, int index){
    if(index >= n) {
        if(x == 1)  return true;
        return false;
    }

    //Multiply
    bool multi = solve(v, n, x * v[index], index + 1);

    //Division
    bool div = false;
    if(x >= v[index]){
        div = solve(v, n, x / v[index], index + 1);
    }

    return multi || div;
}

int canYouGetOne(int n, vector<int> &v) {
    if(solve(v, n, 1, 0)){
        return 1;
    }
    return 0;
}

int main(){
    vector<int> v = {2, 2, 4};
    cout<<canYouGetOne(v.size(), v);
}