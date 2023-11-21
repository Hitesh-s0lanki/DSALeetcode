#include<iostream>
#include<vector>
using namespace std;

int howManySatisfy(int n, int k, vector<int>& a) {

    int cnt = 0;

    for(int i = 0 ; i < n ; i++){
        if((i + 2 * k - 1) < n ){
            int P = 0, Q = 0;
            for(int j = i ; j < n && j < i + k ; j++){
                P += a[j];
            }
            for(int j = (i + 2 * k - 1) ; j >= 0 && j >= (i + k) ; j--){
                Q += a[j];
            }
            if(P > Q) cnt++;
        }
    }

    return cnt;
}

int main(){
    vector<int> a = {1, 0, 0, -2, -5};
    cout<<howManySatisfy(5, 2, a);
}
