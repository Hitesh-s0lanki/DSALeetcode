#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int findKthSmallest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int i=0;
        for( ; i<k ;i++){
            pq.push(nums[i]);
        }
        while(i<nums.size()){
            if(pq.top()>nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
            i++;
        }
        return pq.top();
}
int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int> ,greater<int>> pq;
        int i=0;
        for( ; i<k ;i++){
            pq.push(nums[i]);
        }
        while(i<nums.size()){
            if(pq.top()<nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
            i++;
        }
        return pq.top();
}
int main(){
    vector<int> nums={3,2,1,5,6,4};
    cout<<findKthLargest(nums,2);//5
}