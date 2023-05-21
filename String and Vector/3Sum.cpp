#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        sort(temp.begin(),temp.end());
                        bool check=true;
                        for (auto x:ans){
                            if(x==temp)
                            check=false;
                        }
                        if(check)
                        ans.push_back(temp);
                    }
                }
            }
        }
        return ans;
}
int main(){
    vector<int> a={-1,0,1,2,-1,-4};
    vector<vector<int>> ans=threeSum(a);
    for(auto i : ans){
        for(auto x:i){
            cout<<x<<"\t";
        }
        cout<<endl;
    }
}