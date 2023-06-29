class Solution {
    int solve(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>&dp){

        if(i==triangle.size()-1)return triangle[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int down=triangle[i][j]+solve(triangle, i+1, j, dp);
        int dag=triangle[i][j]+solve(triangle, i+1, j+1, dp);

        return dp[i][j]=min(down, dag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(triangle, 0, 0, dp);
    }
};