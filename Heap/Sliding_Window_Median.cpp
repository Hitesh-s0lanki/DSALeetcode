#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
    public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    double median;
    void addnum(int num){
        if(maxheap.empty() || maxheap.top() > num){
            maxheap.push(num);
            if(maxheap.size() > minheap.size()+1){
                minheap.push(maxheap.top());
                maxheap.pop();
            }
        }
        else{
            minheap.push(num);
            if(minheap.size() > maxheap.size()){
                maxheap.push(minheap.top());
                minheap.pop();
            }
        }
    }
    void erase(int val){
        if(maxheap.top() >= val){
            vector<int> temp;
            while(maxheap.top() != val){
                temp.push_back(maxheap.top());
                maxheap.pop();
            }
            maxheap.pop();
            for(auto i:temp){
                maxheap.push(i);
            }
        }
        else{
            vector<int> temp;
            while(minheap.top() != val){
                temp.push_back(minheap.top());
                minheap.pop();
            }
            minheap.pop();
            for(auto i:temp){
                minheap.push(i);
            }
        }
    }
    double findMedian(int k){
        if(k & 1){
            median = maxheap.top();
        }
        else{
            median = maxheap.top()+minheap.top();
            median /= 2; 
        }
        return median;
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        for(int i=0;i<nums.size();i++){
            if(i<k){
                addnum(nums[i]);
                if(i+1 == k){
                    ans.push_back(findMedian(k));
                }
            }
            else{
                erase(nums[i-k]);
                addnum(nums[i]);
                ans.push_back(findMedian(k));
            }
        }
        return ans;
    }
};
int main(){
    vector<int> nums={2147483647,1,2,3,4,5,6,7,2147483647};
    Solution s;
    vector<double> ans = s.medianSlidingWindow(nums,2);
    for(auto i:ans){
        cout<<i<<"\t";
    }
}