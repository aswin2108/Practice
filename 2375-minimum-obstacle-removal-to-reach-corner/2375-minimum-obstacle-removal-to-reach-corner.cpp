class Solution {
private:
    int bsf(vector<vector<int>>& grid){
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        int dr[4]={0, 0, 1, -1};
        int dc[4]={1, -1, 0, 0};

        dist[0][0]=0;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;

        pq.push({0, {0, 0}});
        while(pq.size()){
            auto top=pq.top();
            pq.pop();

            int i=top.second.first, j=top.second.second, o=top.first;
            for(int k=0;k<4;k++){
                int x=i+dr[k];
                int y=j+dc[k];
                if(x<0 || x>=n || y<0 || y>=m) continue;
                int wt=0;
                if(grid[i][j]==1){
                    wt=1;
                }
                if(o+wt<dist[x][y]){
                    dist[x][y]=o+wt;
                    pq.push({o+wt, {x, y}});
                }
            }
        }
        return dist[n-1][m-1];
    }
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        return bsf(grid);
    }
};