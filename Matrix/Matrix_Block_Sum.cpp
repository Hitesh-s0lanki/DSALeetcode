#include<iostream>
#include<vector>
using namespace std;

int matSum(vector<vector<int>> mat,int s,int e,int n,int m){
    int sum=0;
    for(int i=s;i<=n;i++){
        for(int j=e;j<=m;j++){
            sum+=mat[i][j];
        }
    }
    return sum;
}
// i - k <= r <= i + k,
// j - k <= c <= j + k
vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> ans;
        for(int row=0 ; row<m ; row++){
            vector<int> temp;
            for(int col=0 ;col < n ; col++){
                int s = (row-k < 0) ? 0: row-k;
                int e = (col-k < 0) ? 0: col-k;
                int i = (row+k >= m) ? m-1 :row+k;
                int j = (col+k >= n) ? n-1 :col+k;
                temp.push_back(matSum(mat,s,e,i,j));
            }
            ans.push_back(temp);
        }

        return ans;
}

int main(){
    // [[1,2,3],[4,5,6],[7,8,9]], k = 1
    vector<vector<int>> mat={{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> ans = matrixBlockSum(mat,1);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<"\t";
        }
        cout<<endl;
    }
    // cout<<matSum(mat,0,0,1,1);
}