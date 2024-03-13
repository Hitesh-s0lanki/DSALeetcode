#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int i = 0;

        while(i < nums.size() - 2){
            int k = i + 1;
            int j = nums.size() - 1;

            while(k < j){
                if(nums[i] + nums[j] + nums[k] == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    k++;
                    j--;
                } else if(nums[i] + nums[j] + nums[k] > 0) {
                    j--;
                } else {
                    k++;
                }
            }
            i++;
        } 

        return ans;
}

int main(){
    vector<int> nums = {0, 0, 0, 0};

    vector<vector<int>> ans = threeSum(nums);

    for(vector<int> val:ans){
        cout<<"[";
        for(int i:val){
            cout<<i<<", ";
        }
        cout<<"]"<<endl;
    }
}