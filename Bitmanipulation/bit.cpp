#include<iostream>
#include<vector>
#include<map>
using namespace std;
int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;

        for (int num : nums) {
            ones ^= (num & ~twos);
            twos ^= (num & ~ones);
        }

        return ones;
    }
int main(){
    vector<int> nums = {2,2,3,2};
    cout<<singleNumber(nums);
} 