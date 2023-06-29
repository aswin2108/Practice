class Solution {
    long long int path(vector<vector<int>>& v, int i, int j, vector<vector<int>>& dp){
        if(i==0 && j==0){
            return v[i][j];
        }
        if(i<0 || j<0)return 80000000;

        if(dp[i][j]!=-1)return dp[i][j];

        long long int up=v[i][j]+path(v, i-1, j, dp);
        long long int left=v[i][j]+path(v, i, j-1, dp);

        return dp[i][j]=min(up, left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        // return path(grid, n-1, m-1, dp);

        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) dp[0][0]=grid[0][0];
                else{
                    int up=grid[i][j], left=grid[i][j];
                    if(i>0)up+=dp[i-1][j];
                    else up+=1e9;
                    if(j>0)left+=dp[i][j-1];
                    else left+=1e9;
                    dp[i][j]=min(up, left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};