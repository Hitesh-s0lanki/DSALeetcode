#include<iostream>
#include<vector>
using namespace std;

int solveRecursive(vector<int> nums,int n){
    if ( n < 0)
        return 0;
    if (n == 0)
        return nums[0];

    int incl = solveRecursive(nums, n - 2) + nums[n];
    int execu = solveRecursive(nums , n - 1);

    return max(incl,execu);
}

int solveMeMorization(vector<int> nums,int n,vector<int> &dp){
    if ( n < 0)
        return 0;
    if (n == 0)
        return nums[0];
    
    if (dp[n] != -1)
        return dp[n];

    int incl = solveMeMorization(nums, n - 2 , dp) + nums[n];
    int execu = solveMeMorization(nums , n - 1 , dp);

    dp[n] = max(incl,execu);
    return dp[n];
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();

    // return solveRecursive(nums,n-1);

    vector<int> dp(n,-1);
    return solveMeMorization(nums,n-1,dp);

}
int main(){
    vector<int> nums = {2, 1, 4, 9};
    cout<<maximumNonAdjacentSum(nums);
}