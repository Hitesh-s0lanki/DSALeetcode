#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        if(numRows==0)
        return triangle;

        triangle={{1}};
        for(int i=1;i<numRows;i++){
            vector<int> temp;
            for(int j=0;j<triangle[i-1].size()+1;j++){
                if(j==0||j==triangle[i-1].size()){
                    temp.push_back(1);
                }
                else{
                    temp.push_back(triangle[i-1][j]+triangle[i-1][j-1]);
                }
            }
            triangle.push_back(temp);
        }
    return triangle;
 }
int main(){
    vector<vector<int>> ans=generate(5);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<"\t";
        }
        cout<<endl;
    }
}