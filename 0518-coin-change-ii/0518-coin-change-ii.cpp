class Solution {
    int solve(int idx, int amt, vector<int>&coins, vector<vector<int>>&dp){
        if(idx==0){
            return (amt%coins[0]==0);
        }
        if(dp[idx][amt]!=-1)return dp[idx][amt];
        int notPick=solve(idx-1, amt, coins, dp);
        int pick=0;
        if(coins[idx]<=amt){
            pick=solve(idx, amt-coins[idx], coins, dp);
        }
        return dp[idx][amt] = pick+notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return solve(n-1, amount, coins, dp);
    }
};