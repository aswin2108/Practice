class Solution {
    int path(int m, int n, vector<vector<int>>&dp){
        if(m==0 || n==0){
            return 1;
        }
        if(dp[m][n]!=-1)return dp[m][n]; 
        int up=path(m-1, n, dp);
        int left=path(m, n-1, dp);
        return dp[m][n] = up+left;
    }
public:
   int cnt=0;
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return path(m-1,n-1,dp);
    }
};