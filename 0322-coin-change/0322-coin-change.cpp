class Solution {
    int solve(vector<int>&coins, int n, int amt, vector<vector<int>>&dp){
        if(n==0){
            return (amt%coins[0]==0) ? amt/coins[0] : 1e9;
        }

        if(dp[n][amt]!=-1)return dp[n][amt];

        int notPick=solve(coins, n-1, amt, dp);
        int pick=1e9;
        if(coins[n]<=amt){
            pick=1+solve(coins, n, amt-coins[n], dp);
        }
        return dp[n][amt]=min(pick, notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans = solve(coins, n-1, amount, dp);
        return (ans>=1e9) ? -1 : ans;
    }
};