class Solution {
    int paths(vector<vector<int>>grid, int n, int m, vector<vector<int>>&dp){
        if(n<0 || m<0 || grid[n][m]==1)return 0;
        if(n==0 && m==0)return 1;
        if(dp[n][m]!=-1)return dp[n][m];
        int left=paths(grid, n-1, m, dp);
        int right=paths(grid, n, m-1, dp);
        return dp[n][m]=left+right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(), m=obstacleGrid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return paths(obstacleGrid, n-1, m-1, dp);
    }
};