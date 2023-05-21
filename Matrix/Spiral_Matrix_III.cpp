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

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {

    vector<vector<int>> ans;
    int row=rStart;
    int col=cStart;
    int rowUp = row - 1;
    int colBack =col - 1;
    int rowDown = row + 1;
    int colFront = col +1;

    int count = 0;
    int total = rows * cols ; 
    while(count < total){
        //Right
        while(col < colFront){
            if(col < cols  && col >=0 && row >=0 && row < rows){
                ans.push_back({row,col});
                count++;
            }
            col++;
        }
        //Down
        while(row < rowDown){
            if(col < cols  && col >=0 && row >=0 && row < rows){
                ans.push_back({row,col});
                count++;
            }
            row++;
        }
        //left
        while(col > colBack){
            if(col < cols  && col >=0 && row >=0 && row < rows){
                ans.push_back({row,col});
                count++;
            }
            col--;
        }
        //Up
        while(row > rowUp){
            if(col < cols  && col >=0 && row >=0 && row < rows){
                ans.push_back({row,col});
                count++;
            }
            row--;
        }
        rowUp--;
        colBack--;
        rowDown++;
        colFront++;
    }
    return ans;
}
int main(){
    int rows = 5, cols = 6, rStart = 1, cStart = 4 ;
    vector<vector<int>> ans = spiralMatrixIII(rows,cols,rStart,cStart);

    for(auto i : ans){
        for(auto j : i){
            cout<<j<<"\t";
        }
        cout<<endl;
    }
}