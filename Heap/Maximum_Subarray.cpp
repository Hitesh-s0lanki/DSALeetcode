#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int maxSubArray(vector<int>& nums){
    int maxi=INT_MIN,sum=0;

    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum > maxi){
            maxi = sum;
        }
        if(sum < 0){
            sum=0;
        }
    }

    return maxi;
}
int main(){
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums);
}