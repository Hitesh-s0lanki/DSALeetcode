#include<iostream>
#include<vector>

using namespace std;
void solve(vector<int> nums,vector<vector<int>> &ans,int index){
    //base case
    if(index>=nums.size()){
        ans.push_back(nums);
        return;
    }
    //method
    for(int i=index;i<nums.size();i++){
        swap(nums[index],nums[i]);
        solve(nums,ans,index+1);
        swap(nums[index],nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        solve(nums,ans,index);
        return ans;
    }
int main(){
    vector<int> a={1,2,3};
    vector<vector<int>> ans=permute(a);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<"\t";
        }
        cout<<endl;
    }
}