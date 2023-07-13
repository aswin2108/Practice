class Solution {
    int solve(vector<vector<int>>& pairs, int n, int prev, vector<vector<int>>&dp){
        if(n == 0){
            return (pairs[0][1] < pairs[prev][0]);
        }
        if(dp[prev][n] != -1) return dp[prev][n];

        int notPick = solve(pairs, n-1, prev, dp);
        int pick=0;
        if(prev == 0 || pairs[n][1] < pairs[prev][0]){
            pick = 1 + solve(pairs, n-1, n, dp);
        }

        return dp[prev][n] = max(pick, notPick);
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<vector<int>> dp(1003,vector<int>(1003,-1));
        int ans = solve(pairs, n-1, 0, dp);
        return max(ans, 1);
    }
};
