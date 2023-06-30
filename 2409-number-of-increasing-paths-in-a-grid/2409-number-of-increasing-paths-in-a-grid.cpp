class Solution {
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>&dp){
        if(dp[i][j]!=-1)return dp[i][j];

        int ans=1;
        int dr[4]={0, -1, 0, 1};
        int dc[4]={1, 0, -1, 0};

        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[i][j]<grid[nr][nc]){
                ans=(ans%mod + dfs(grid, nr, nc, dp)%mod)%mod;
            }
        }
        return dp[i][j]=ans%mod;
    }
public:
    long long int mod=1e9+7;
    int countPaths(vector<vector<int>>& grid) {
        long long int cnt=0;
        vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(), -1));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                cnt=(cnt%mod + dfs(grid, i, j, dp)%mod)%mod;
            }
        }
        return (int)(cnt%mod);
    }
};