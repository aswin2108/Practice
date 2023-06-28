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
        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0)dp[i][j]=1;
                else{
                    int up=dp[i-1][j];
                    int left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};