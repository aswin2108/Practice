class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1)return -1;
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        dist[0][0]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        while(q.size()){
            int d=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            
            if(x==n-1 && y==m-1){
                return d;
            }
            
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nr=x+i;
                    int nc=y+j;
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0 && d+1<dist[nr][nc]){
                        dist[nr][nc]=d+1;
                        q.push({d+1, {nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};