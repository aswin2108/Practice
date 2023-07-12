class Solution {
    int solve(int n, int amt, vector<int>&coins, vector<vector<int>>&dp){
        if(n==0){
            return (amt%coins[0]==0);
        }
        if(dp[n][amt]!=-1)return dp[n][amt];
        int notPick = solve(n-1, amt, coins, dp);
        int pick=0;
        if(coins[n]<=amt){
            pick=solve(n, amt-coins[n], coins, dp);
        }
        return dp[n][amt] = pick+notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return solve(n-1, amount, coins, dp);
    }
};