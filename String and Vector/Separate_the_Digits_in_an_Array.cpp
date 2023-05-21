#include<iostream>
#include<vector>
using namespace std;
vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int i=0;
        while(i<nums.size()){
            string temp=to_string(nums[i]);
            int j=0;
            while(j<temp.length()){
                ans.push_back(temp[j]-'0');
                j++;
            }
            i++;
        }
        return ans;
    }
int main(){
    vector<int> a={13,25,83,77};
    vector<int> ans=separateDigits(a);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\t";
    }
}