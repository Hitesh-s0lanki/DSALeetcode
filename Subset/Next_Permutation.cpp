#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve(vector<int> nums,vector<vector<int>> &ans,int index){
    if(index >= nums.size()){
        ans.push_back(nums);
        return ;
    }
    for(int i=index;i<nums.size();i++){
        swap(nums[index],nums[i]);
        solve(nums,ans,index+1);
        swap(nums[index],nums[i]);
    }
}
void nextPermutation(vector<int>& nums) {
    vector<vector<int>> ans ;
    vector<int> temp = nums;
    sort(nums.begin(),nums.end());
    solve(nums,ans,0);
    int val = 0;
    for(auto i:temp){
        cout<<i<<"\t";
    }
    for(int i=0;i<ans.size();i++){
        if(ans[i] == temp){
            val = i;
        }
    }
    if(val == ans.size()-1){
        nums =  ans[0];
    }
    else
        nums = ans[val+1];
}
int main(){
    vector<int> nums = {3,2,1};
    nextPermutation(nums);
    for(auto i:nums)
        cout<<i<<"\t";
}