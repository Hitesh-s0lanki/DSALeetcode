#include<iostream>
#include<vector>
using namespace std;
int triangularSum(vector<int>& nums) {
    int size=0;
    int ans=nums[0];
        while(size!=1&&nums.size()!=1){
            vector<int> temp;
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]+nums[i+1]<10)
                temp.push_back(nums[i]+nums[i+1]);
                else
                temp.push_back((nums[i]+nums[i+1])%10);
            }
            size=temp.size();
            nums=temp;
            ans=temp[0];
        }
        return ans;
    }
int main(){
    vector<int> a={1,2,3,4,5};
    cout<<"the sum this is "<<triangularSum(a);
}