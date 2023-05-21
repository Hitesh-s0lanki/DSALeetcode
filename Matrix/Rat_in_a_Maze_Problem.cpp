#include<iostream>
#include<vector>
#include<map>
using namespace std;
bool isSafe(int row,int col,vector<vector<int>> &m,int n,vector<vector<int>> condition){
    if((row<n&&col<n)&&(row>=0&&col>=0)&&(m[row][col]==1&&condition[row][col]==0))
        return true;
    return false;
}
void solve(int row,int col,vector<vector<int>> &m, int n,string output,vector<string> &ans,vector<vector<int>> condition){
    //base case
    if(row==n-1&&col==n-1){
        ans.push_back(output);
        return;
    }
    condition[row][col]=1;
    if(isSafe(row-1,col,m,n,condition)){
        output.push_back('U');
        solve(row-1,col,m,n,output,ans,condition);
        output.pop_back();
    }
    if(isSafe(row+1,col,m,n,condition)){
        output.push_back('D');
        solve(row+1,col,m,n,output,ans,condition);
        output.pop_back();
    }
    if(isSafe(row,col-1,m,n,condition)){
        output.push_back('L');
        solve(row,col-1,m,n,output,ans,condition);
        output.pop_back();
    }
    if(isSafe(row,col+1,m,n,condition)){
        output.push_back('R');
        solve(row,col+1,m,n,output,ans,condition);
        output.pop_back();
    }
    condition[row][col]=0;
    return;
}
vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string output;
        if(m[0][0]==0){
            return {"-1"};
        }
        vector<vector<int>> condition;
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                temp.push_back(0);
            }
            condition.push_back(temp);
        }
        solve(0,0,m,n,output,ans,condition);
        if(ans.size()==0){
            return {"-1"};
        }
        return ans;
    }
int main(){
    vector<vector<int>> m={{1,1},{1,1}};
          vector<string> ans=findPath(m,2);                  
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}