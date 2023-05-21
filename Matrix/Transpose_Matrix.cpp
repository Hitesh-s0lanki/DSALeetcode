#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                temp.push_back(matrix[j][i]);
            }
            ans.push_back(temp);
        }
        return ans;
}
int main(){
    // [[1,2,3],[4,5,6],[7,8,9]]

    vector<vector<int>> mat ={{1,2,3},{4,5,6}};
    vector<vector<int>> ans = transpose(mat);
    for(auto i: ans){
        for(auto j: i){
            cout<<j<<"\t";
        }
        cout<<endl;
    }
}