class Solution {
    int solve(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=n || j>=m)return 0;
        if(grid[i][j]==1)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(i==n-1 && j==m-1)return 1;
        int down=solve(i+1, j,n, m, grid, dp);
        int right=solve(i, j+1,n, m, grid, dp);
        return dp[i][j] = down+right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(), m=obstacleGrid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(0, 0, n, m, obstacleGrid, dp);
    }
};