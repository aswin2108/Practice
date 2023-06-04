class Solution {
    bool isValid(vector<vector<char>>& grid, vector<vector<bool>>& vis, int r, int c){
        int n=grid.size(), m=grid[0].size();
        if(r>=0 && r<n && c>=0 && c<m && grid[r][c]=='1' && !vis[r][c])return true;
        return false;
    }
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int r, int c){
        
        vis[r][c]=1;
        
        if(isValid(grid, vis, r+1, c))dfs(grid, vis, r+1, c);
        if(isValid(grid, vis, r-1, c))dfs(grid, vis, r-1, c);
        if(isValid(grid, vis, r, c+1))dfs(grid, vis, r, c+1);
        if(isValid(grid, vis, r, c-1))dfs(grid, vis, r, c-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m,false));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return cnt;
    }
};