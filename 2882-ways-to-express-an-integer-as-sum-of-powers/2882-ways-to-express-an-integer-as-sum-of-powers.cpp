class Solution {
    int mod=1e9+7;
    int solve(int idx, int n, int &x, vector<vector<int>>&dp){
        if(n==0)return 1;
        if(n<0)return 0;

        int pick=0;
        long long val=pow(idx, x);
        if(val>n)return 0;

        if(dp[idx][n]!=-1)return dp[idx][n];
        
        pick=solve(idx+1, n-val, x, dp)%mod;
        
        int notPick=solve(idx+1, n, x, dp)%mod;

        return dp[idx][n]=(pick+notPick)%mod;
    }
public:
    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(1, n, x, dp);
    }
};