#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Operation Ninja can perform
// Type 1 : add b to a
// Type 2 : 1.create a copy of b
//        : 2.reverse copyb
//        : 3.b += copyb 

int sumArray(vector<int> c){
    int sum = 0;
    for(auto i : c){
        if(i < 0){
            sum += (-1 * i);
        }else{
            sum += i;
        }
    }
    return sum;
}

bool sameArray(vector<int> a, vector<int> c,int n){
    for(int i = 0;i < n; i++){
        if(a[i] != c[i]) return false;
    }
}

vector<int> typeOne(vector<int> a, vector<int> b, int n){
    for(int i =0 ;i < n; i++){
        a[i] += b[i];
    }
    return a;
}

vector<int> reverseArray(vector<int> b){
    reverse(b.begin(), b.end());
    return b;
}

bool solve(vector<int> a, vector<int> b, vector<int> c,int n, int sum){
    if(sameArray(a, c, n)){
        return true;
    }   
    if(sumArray(b) > sum || sumArray(a) > sum ) return false;

    // Type 1
    bool type1 = solve(typeOne(a, b, n), b, c, n, sum);

    //Type 2;
    b = typeOne(b, reverseArray(b), n);
    bool type2 = solve(a, b, c, n, sum);

    return type1 || type2;
}

int interestingOperation(int n, vector<int> b, vector<int> c) {
    vector<int> a(n, 0);

    if(solve(a, b, c, n, sumArray(c))) return 1;

    return 0;
}

int main(){

    vector<int> b = {1, 2, 2};
    vector<int> c = {3, 4, 3};
    int n = b.size();

    cout<<interestingOperation(n, b, c);
}