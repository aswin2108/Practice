class Solution {
    int cherry(int r1, int c1, int r2, int n, vector<vector<int>>&grid, vector<vector<vector<int>>>& dp){
        int c2=r1+c1-r2;

        if(r1>=n || c1>=n || r2>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return -1e8;
        }

        if(dp[r1][c1][r2]!=-1)return dp[r1][c1][r2];

        if(r1==n-1 && c1==n-1)return grid[r1][c1];
        int val=0;
        if(r1==r2 && c1==c2){
            val+=grid[r1][c1];
        }
        else{
            val+=grid[r1][c1] + grid[r2][c2];
        }

        int a=cherry(r1+1, c1, r2+1, n, grid, dp);
        int b=cherry(r1+1, c1, r2, n, grid, dp);
        int c=cherry(r1, c1+1, r2+1, n, grid, dp);
        int d=cherry(r1, c1+1, r2, n, grid, dp);

        val+=max({a,b,c,d});
        return dp[r1][c1][r2]=val;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return max(0, cherry(0,0,0,n,grid, dp));
    }
};