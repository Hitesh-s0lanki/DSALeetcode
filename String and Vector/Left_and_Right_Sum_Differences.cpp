#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> leftRigthDifference(vector<int>& nums) {
    int i=0;
    vector<int> left={0};
    vector<int> right={0};
        while(i<nums.size()-1){
            left.push_back(left[left.size()-1]+nums[i]);
            right.push_back(right[right.size()-1]+nums[nums.size()-1-i]);
            i++;
        }
        reverse(right.begin(),right.end());
        vector<int> ans;
        i=0;
        while(i<nums.size()){
            ans.push_back(abs(left[i]-right[i]));
            i++;
        }
        return ans;
}
int main(){
    vector<int> a={10,4,8,3};
    vector<int> ans=leftRigthDifference(a);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\t";
    }
}