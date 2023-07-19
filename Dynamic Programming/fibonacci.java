class fibonacci{
    public static int fib(int n ,int[] dp){
        if(n==0 || n==1){
            return n;
        }
        if(dp[n] != -1)
            return dp[n];

        dp[n] = fib(n-2, dp) + fib(n-1, dp);

        return dp[n];
    }
    public static void main(String[] args) {
        int[] dp = new int[11];
        for(int i=0;i<11;i++){
            dp[i] = -1;
        }
       for(int i=0;i<10;i++)
            System.out.print(fib(i,dp)+" ");
    }
}