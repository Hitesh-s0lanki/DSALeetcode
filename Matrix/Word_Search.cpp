#include <iostream>
#include <vector>
using namespace std;
bool solve(int row,int col,int index,string word,vector<vector<char>> &board){
    if (index >= word.length())
        return true;

    if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index])
        return false;

    char element = board[row][col];
    board[row][col] = '#';

    bool ans = solve(row - 1, col,index + 1,word ,board ) ||
               solve(row + 1, col,index + 1,word ,board ) ||
               solve(row, col + 1,index + 1,word ,board ) ||
               solve(row, col - 1,index + 1,word ,board ) ;
    
    board[row][col] = element;

    return ans;

}

bool exist(vector<vector<char>>& board, string word) {  
    int m = board.size();
    int n = board[0].size();

    for(int row = 0 ; row < m ; row++){
        for(int col = 0;col < n; col++){
            if(solve(row,col,0,word,board))
                return true;
        }
    }
    return false;
}
int main()
{
    // [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
    vector<vector<char>> ch = { {'A','B','C','E'},
                                {'S','F','C','S'},
                                {'A','D','E','E'}};
    string word = "ABCB";
    cout << exist(ch, word);
}
// aabaabaabbbaaaaabababbababbababaaaab