#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix;
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            temp.push_back(0);
        }
        matrix.push_back(temp);
    }

        int row=n;
        int col=n;
        int startrow=0;
        int startcol=0;
        int endrow=row-1;
        int endcol=col-1;
        
        int count=0;
        int total=row*col;
        while(count<total){
            
            //for first row
            for(int index=startcol;count<total&&index<=endcol;index++){
                matrix[startrow][index]=1+count++;
            }
            startrow++;
            
            //for last column
            for(int index=startrow;count<total&&index<=endrow;index++){
                matrix[index][endcol]=1+count++;
            }
            endcol--;
            
            //for last row
            for(int index=endcol;count<total&&index>=startcol;index--){
                matrix[endrow][index]=1+count++;
            }
            endrow--;
            
            //for first column
            for(int index=endrow;count<total&&index>=startrow;index--){
                matrix[index][startcol]=1+count++;
            }
             startcol++;
            
            
        }

        return matrix;
}
int main(){
    vector<vector<int>> ans = generateMatrix(3);
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<"\t";
        }
        cout<<endl;
    }
}