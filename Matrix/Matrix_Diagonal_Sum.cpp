#include<iostream>
#include<vector>
using namespace std;

void solve(vector<vector<int>>& mat,int &ans,int row,int col,int n,int m){
    if(row >= mat.size() || col >= mat[0].size() || row < 0 || col < 0)
        return;
    cout<<mat[row][col]<<endl;
    ans+=mat[row][col];

    return solve(mat,ans,row+n,col+m,n,m);
}
int diagonalSum(vector<vector<int>>& mat) {
    int ans=0;
    int row=mat.size()-1;
    int col=mat[0].size()-1;
        solve(mat,ans,0,0,1,1);
        solve(mat,ans,0,col,1,-1);
    if(((row+1)*(col+1))%2 != 0){
        cout<<"hii"<<endl;
        return ans - mat[(row+1)/2][(col+1)/2];
    }
    return ans;
}
int main(){
    vector<vector<int>> mat={{7,3,1,9},{3,4,6,9},{6,9,6,6},{9,5,8,5}};
    cout<<diagonalSum(mat);
}