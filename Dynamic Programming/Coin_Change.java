public class Coin_Change {
    public int solveRecursive(int[] coins, int amount){
        if (amount == 0)
            return 0;
    
        if(amount < 0)
            return Integer.MAX_VALUE;

        int mini = Integer.MAX_VALUE;
        
        for (int j : coins) {
            int ans = solveRecursive(coins, amount - j);

            if(ans != Integer.MAX_VALUE){
                mini = Math.min(1+ans,mini);
            }
        }

        return mini;
    }
    public int solveMemorization(int[] coins, int amount,int[] dp){
        if (amount == 0)
            return 0;
    
        if(amount < 0)
            return Integer.MAX_VALUE;

        if(dp[amount] != -1)
            return dp[amount];

        int mini = Integer.MAX_VALUE;
        
        for (int j : coins) {
            int ans = solveRecursive(coins, amount - j);

            if(ans != Integer.MAX_VALUE){
                mini = Math.min(1+ans,mini);
            }
        }

        
        return dp[amount] = mini;
    }

    public int solveTabulation(int[] coins, int amount){

        int[] dp = new int[amount + 1];
        for (int i = 1 ; i < amount+1; i++) {dp[i] = Integer.MAX_VALUE;}
        
        dp[0] = 0;

        for(int i = 1 ; i <= amount ;i++){
            //i m trying to solve for evry amount 
            for(int j =0;j<coins.length;j++){
                if(i - coins[j] >= 0 && dp[i - coins[j]] != Integer.MAX_VALUE){
                    dp[i] = Math.min(dp[i], 1 + dp[i - coins[j]] );
                }
            }
        }

        if(dp[amount] == Integer.MAX_VALUE)
            return -1;

        return dp[amount];
    }

    public int coinChange(int[] coins, int amount) {

        // int ans = solveRecursive(coins,amount);

        // int[] dp = new int[amount + 1];
        // for (int i = 0 ; i < amount+1; i++) {dp[i] = -1;}
        // int ans = solveMemorization(coins,amount,dp);

        // if(ans == Integer.MAX_VALUE)
        //     return -1;

        // return ans;

        return solveTabulation(coins, amount);
    }
    public static void main(String[] args) {
        int[] coins = {1,2,5}; 
        int amount = 11;

        Coin_Change c = new Coin_Change();

        System.out.println(c.coinChange(coins, amount));
    }
}
