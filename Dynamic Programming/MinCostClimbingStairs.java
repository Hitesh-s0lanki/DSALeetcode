public class MinCostClimbingStairs {
    public int solve(int[] cost ,int n){
        if(n == 0 || n == 1){
            return cost[n];
        }
        int ans = Math.min(solve(cost, n-1), solve(cost, n-2)) + cost[n];

        return ans;
    }
    public int solve2(int[] cost,int n,int[] dp){
        if(n == 1||n == 0){
            return cost[n];
        }
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] = Math.min(solve2(cost, n-1, dp),solve2(cost, n-2, dp)) + cost[n];

        return dp[n];
    }
    public int solve3(int[] cost,int n){
        //base two condition
        int step1 = cost[0];
        int step2 = cost[1];

        for(int i=2;i<cost.length;i++){
            int curr = Math.min(step1, step2) + cost[i];
            step1 = step2;
            step2 = curr;
        }

        return Math.min(step1, step2);
    }
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        // int ans = Math.min(solve(cost,n-1),solve(cost,n-2));
        // return ans;

        // int[] dp = new int[n+1];
        // for (int i =0 ;i<n;i++) {
        //     dp[i] = -1;
        // }

        // int ans = Math.min(solve2(cost,n-1,dp),solve2(cost, n-2,dp));
        
        // return ans;

        return solve3(cost, n);
    }
    public static void main(String[] args) {
        int[] cost = {1,100,1,1,1,100,1,1,100,1};

        MinCostClimbingStairs m = new MinCostClimbingStairs();
        System.out.println(m.minCostClimbingStairs(cost));
    }
    
}