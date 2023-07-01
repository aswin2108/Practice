class Solution {
    bool dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>&vis, int mid){
        if(grid[i][j]>mid)return false;
        vis[i][j]=true;
        int dr[4]={0,-1,1,0};
        int dc[4]={1,0,0,-1};
        bool ans=false;
        for(int k=0;k<4;k++){
            int ni=i+dr[k];
            int nj=j+dc[k];
            if(ni>=0 && nj>=0 && ni<grid.size() && nj<grid.size() && !vis[ni][nj] && grid[ni][nj]<=mid){
                if(nj==0 && ni==0)return true;
                ans|=dfs(grid, ni, nj, vis, mid);
            }
        }
        return ans;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int lo=grid[0][0], hi=n*n-1;
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            vector<vector<bool>>vis(n, vector<bool>(n, false));
            if(dfs(grid, n-1, n-1, vis, mid)){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};