#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<string> board,int row,int col,int n){
    //row check left
    int tempRow = row ;
    int tempCol = col - 1;
    while(tempCol >= 0){
        if(board[tempRow][tempCol--] == 'Q')
            return false;
    }

    //row check Right
    tempRow = row ;
    tempCol = col + 1;
    while(tempCol != n){
        if(board[tempRow][tempCol++] == 'Q')
            return false;
    }

    //Up check
    tempRow = row - 1;
    tempCol = col;
    while(tempRow >= 0){
        if(board[tempRow--][tempCol] == 'Q')
            return false;
    }

    //Down check
    tempRow = row + 1;
    tempCol = col;
    while(tempRow != n){
        if(board[tempRow++][tempCol] == 'Q')
            return false;
    }

    //upper left check
    tempRow = row - 1;
    tempCol = col - 1;
    while(tempRow >= 0 && tempCol >= 0){
        if(board[tempRow--][tempCol--] == 'Q')
            return false;
    }

    //upper Right check
    tempRow = row - 1;
    tempCol = col + 1;
    while(tempRow >= 0 && tempCol != n){
        if(board[tempRow--][tempCol++] == 'Q')
            return false;
    }

    //Lower Right check
    tempRow = row + 1;
    tempCol = col - 1;
    while(tempRow != n && tempCol >= 0){
        if(board[tempRow++][tempCol--] == 'Q')
            return false;
    }
    
    //upper Right check
    tempRow = row + 1;
    tempCol = col + 1;
    while(tempRow != n && tempCol != n){
        if(board[tempRow++][tempCol++] == 'Q')
            return false;
    }

    return true;
}
void solve(int col ,vector<vector<string>> &ans,vector<string> board,int n){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row = 0;row < n ; row++){
        if(isSafe(board,row,col,n)){
            board[row][col]='Q';
            solve(col+1,ans,board,n);
            //Backtracking
            board[row][col]='.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {

    vector<vector<string>> ans;
    vector<string> board(n,string(n,'.'));

    solve(0,ans,board,n);

    return ans;
}
int main(){
    int n = 4;
    vector<vector<string>> ans = solveNQueens(n);
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<"\t";
        }
        cout<<endl;
    }
}