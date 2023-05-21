#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<int>> ans){
    for(auto i: ans){
        for(auto j: i){
            cout<<j<<"\t";
        }
        cout<<endl;
    }
}

vector<int> spiralOrder(vector<vector<int>>& matrix){
    vector<int> ans;
    int n = matrix.size();
    int m = matrix[0].size();
    int count=0;
    int total=n*m;

    int colstart = 0;
    int rowstart = 0;
    int colEnd = m-1 ;
    int rowEnd = n-1 ;

    while(count < total){
        //first Row
        for(int i = colstart; i < colEnd ; i++ ){
            ans.push_back(matrix[rowstart][i]);
            count++;
        }
        //last col
        for(int i = rowstart ; i <= rowEnd ; i++){
            ans.push_back(matrix[i][colEnd]);
            count++;
        }
        //last row
        for(int i = colEnd - 1 ; i >= colstart ;i--){
            ans.push_back(matrix[rowEnd][i]);
            count++;
        }
        //first col
        for(int i = rowEnd -1 ; i > rowstart ; i--){
            ans.push_back(matrix[i][colstart]);
            count++;
        }

        rowstart++;
        colstart++;
        colEnd--;
        rowEnd--;
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix ={{1,2,3},{4,5,6},{7,8,9}};
    print(matrix);
    vector<int> ans=spiralOrder(matrix);
    for(auto i: ans){
        cout<<i<<"\t";
    }
}