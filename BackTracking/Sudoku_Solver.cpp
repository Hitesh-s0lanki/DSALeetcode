#include<iostream>
#include<vector>

using namespace std;

bool isSafe(vector<vector<char>> board ,int row ,int col,char ch){
    int n = board.size();
    for(int i=0;i<n;i++){
        //Row Check
        if(board[i][col] == ch)
            return false;
        //Col check
        if(board[row][i] == ch)
            return false;
        //box check
        if(board[3*(row/3)+ i/3][3*(col/3) + i%3] == ch)
            return false;
    }
    return true;
}

bool solve(vector<vector<char>> &board){

    int n = board.size();
    for(int row = 0; row < n ;row++){
        for(int col = 0 ;col < n ; col++){
            if(board[row][col] == '.'){
                for(char ch = '1' ; ch <= '9' ;ch++){
                    if(isSafe(board,row,col,ch)){
                        board[row][col] = ch;

                        bool solution = solve(board);
                        if(solution)
                            return true;
                        else{
                            //BackTracking
                            board[row][col] = '.';
                        }
                    }
                }
                return false;
            }

        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    solve(board);   
}
int main(){
    vector<vector<char>> board ={{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},
                                    {'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},
                                    {'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    solveSudoku(board);
    for(auto i:board){
        for(auto j:i){
            cout<<j<<'\t';
        }
        cout<<endl;
    }
}