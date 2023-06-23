class Solution {
    int solve(int n, int dp[]){
        if(n==1 || n==0)return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=fib(n-1) + fib(n-2);
    }
public:
    int fib(int n) {
        int dp[n+1];
        memset(dp, -1, sizeof dp);
        return solve(n, dp);
    }
};