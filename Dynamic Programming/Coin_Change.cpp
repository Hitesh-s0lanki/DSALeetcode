// Minimum Elements
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int solveRecursive(vector<int> nums,int x){
    if(x == 0)
        return 0;
    if (x < 0)
        return INT_MAX;

    int mini = INT_MAX;
    for(auto i:nums){
        int ans = solveRecursive(nums,x - i);
        if (ans != INT_MAX)
            mini = min(mini,1 + ans);
    }
    return mini;
}
int solveMemorization(vector<int> nums,int x){

    vector<int> dp(x+1,INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= x ; i++ ){
        for (int j = 0; j < nums.size(); j++){
            if(i - nums[j] >= 0 && dp[i - nums[j]] != 0){
                dp[i] = min(dp[i],1 + dp[i - nums[j]]);
            }
        }
    }
    if(dp[x] == INT_MAX)
        return -1;
    
    return dp[x];

}



int minimumElements(vector<int> &num, int x){
    // Recursive call
    // int ans =  solveRecursive(num,x);
    // if(ans == INT_MAX)
    //     return -1;
    // return ans;

    return solveMemorization(num,x);
}
int main(){
    vector<int> nums = {1,2,5};
    int x = 7;
    cout<<solveRecursive(nums,x);
}