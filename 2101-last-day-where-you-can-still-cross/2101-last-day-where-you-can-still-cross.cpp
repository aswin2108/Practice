class Solution {
private:
    bool dfs(vector<vector<int>>&v, vector<vector<bool>>&vis, int i, int j, int n, int m){
        
        vis[i][j]=true;
        if(i==n-1)return true;
        bool flag=false;
        
        int dr[4]={-1, 0, 1, 0};
        int dc[4]={0, -1, 0, 1};

        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && v[nr][nc]==0){
                flag|=dfs(v, vis, nr, nc, n, m);
            }
        }
        return flag;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int lo=0, hi=cells.size()-1;
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            vector<vector<int>>v(row, vector<int>(col, 0));
            vector<vector<bool>>vis(row, vector<bool>(col, false));

            for(int i=0;i<=mid;i++){
                int x=cells[i][0]-1;
                int y=cells[i][1]-1;
                v[x][y]=1;
            }
            bool flag=false;
            for(int i=0;i<col;i++){
                if(!vis[0][i] && v[0][i]==0){
                    flag |= dfs(v, vis, 0, i, row, col);
                }
            }
            if(flag){
                lo=mid+1;
                ans=mid;
            }
            else{
                hi=mid-1;
            }
        }
        return ans+1;
    }
};