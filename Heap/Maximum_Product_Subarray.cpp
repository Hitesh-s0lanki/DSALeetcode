#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxProduct(vector<int>& nums) {
    int maxi = INT_MIN,mul=1;
    for(int i=0;i<nums.size();i++){
        mul*=nums[i];
        if(mul > maxi)
            maxi = mul;
        if(mul < 1){
            mul=1;
        }   
    }
    return maxi;

}

int main(){
    vector<int> nums={2,3,-2,4};
    cout<<maxProduct(nums);
}