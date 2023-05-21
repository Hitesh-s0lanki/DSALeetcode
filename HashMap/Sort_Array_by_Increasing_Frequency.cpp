#include<iostream>
#include<vector>
#include<map>
#include<climits>
using namespace std;
vector<int> frequencySort(vector<int>& nums) {
        
        map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        vector<int> ans;
        int j=0;
        while(j<m.size()){
            int num=0;
            for(auto i:m){
                int mini = INT_MAX;
                if(i.second != 0 && i.second < mini){
                    mini = i.second;
                    num = i.first;
                }
            }
            while(m[num]){
                ans.push_back(num);
                m[num]--;
            }
            j++;
        }
        return ans;
}
int main(){
    vector<int> nums={1,1,2,2,2,3};
    vector<int> ans=frequencySort(nums);
    for(auto i:ans){
        cout<<i<<"\t";
    }
}