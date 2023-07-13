class Solution {
    int solve(int n, int m, string &s1, string &s2, vector<vector<int>>&dp){
        if(n==-1 || m==-1)return 0;
        if(dp[n][m] != -1) return dp[n][m];
        if(s1[n] == s2[m]) return dp[n][m] = 1+solve(n-1, m-1, s1, s2, dp);

        return dp[n][m] = max(solve(n-1, m, s1, s2, dp), solve(n, m-1, s1, s2, dp));
    }
public:
    int longestPalindromeSubseq(string s) {
        string s2=s; 
        reverse(s.begin(), s.end());
        int n=s.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solve(n-1, n-1, s, s2, dp);
    }
};