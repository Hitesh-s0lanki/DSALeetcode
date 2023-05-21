#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int row,int col,vector<vector<char>> &board,int m,int n,vector<vector<int>> condition){
    if((row<m&&col<n)&&(row>=0&&col>=0)&&condition[row][col]==0)
        return true;
    return false;
}
bool solve(int index,int row,int col,vector<vector<char>>& board, string word,vector<vector<int>> condition){
    if(index>=word.length())
        return true;
    condition[row][col]=1;
    int m=board.size();
    int n=board[0].size();
    bool Up=false,Down=false,Left=false,Right=false;
    if(board[row][col]==word[index]){
        cout<<row<<"\t"<<col<<endl;
        if(isSafe(row-1,col,board,m,n,condition)){
            Up=solve(index+1,row-1,col,board,word,condition);
        }
        if(isSafe(row+1,col,board,m,n,condition)){
            Down=solve(index+1,row+1,col,board,word,condition);
        }
        if(isSafe(row,col-1,board,m,n,condition)){
            Left=solve(index+1,row,col-1,board,word,condition);
        }
        if(isSafe(row,col+1,board,m,n,condition)){
            Right=solve(index+1,row,col+1,board,word,condition);
        }
        if(Up||Down||left||Right){
            return true;
        }
    }
        condition[row][col]=0;
        return false;
}
bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> condition;
        for(int i=0;i<m;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                temp.push_back(0);
            }
            condition.push_back(temp);
        }
        int row=0;
        int col=0;
        while(row<m){
            if(solve(0,row,col,board,word,condition))
                return true;
            col++;
            if(col==n){
                col=0;
                row++;
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