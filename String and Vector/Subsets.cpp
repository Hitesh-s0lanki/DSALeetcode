#include<iostream>
#include<vector>
#include<map>
using namespace std;
void CreateSub(int index,vector<int> output,vector<int>& nums,vector<vector<int>> &ans,map<vector<int>,bool> &check){
    //base Case
    if(index>=nums.size()){
        if(!check[output]){
            check[output]=true;
            ans.push_back(output);
        }
        return;
    }
    //exclude
    CreateSub(index+1,output,nums,ans,check);
    //include
    output.push_back(nums[index]);
    CreateSub(index+1,output,nums,ans,check);

}
vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        map<vector<int>,bool> check;
        CreateSub(0,output,nums,ans,check);
        return ans;
}
int main(){
    vector<int> a={1,2,2};
    vector<vector<int>> ans=subsets(a);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<"\t";
        }
        cout<<endl;
    }
}