#include<iostream>
#include<vector>
using namespace std;

bool check(vector<vector<int>>& matrix,int row,int col,int data){
    if(row >= matrix.size() || col >= matrix[0].size() || row < 0 || col < 0){
        return true;
    }
    if(matrix[row][col] != data){
        return false;
    }

    return check(matrix,row+1,col+1,matrix[row][col]);
}

bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int row=0;row < matrix.size() ; row++){
            for(int col = 0;col < matrix[row].size();col += row + 1){
                if(!check(matrix,row+1,col+1,matrix[row][col]))
                    return false;
            }
        }
        return true;
    }
int main(){
    // [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
    vector<vector<int>> mat={{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    cout<<isToeplitzMatrix(mat);
}