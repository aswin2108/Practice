class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;

        int n=heights.size();
        int m=heights[0].size();
        
        vector<vector<int>>grid(n,vector<int>(m,1e9));
        grid[0][0]=0;
        pq.push({0,{0,0}});

        int dr[]={0,-1,0,1};
        int dc[]={1,0,-1,0};

        while(pq.size()){
            auto it=pq.top();
            int diff=it.first;
            int x=it.second.first;
            int y=it.second.second;
            pq.pop();
            if(x==n-1 && y==m-1)return diff;
            for(int i =0;i<4;i++){
                for(int j=0;j<4;j++){
                    int nr=x+dr[i];
                    int nc=y+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m){
                        int newEffort=max(abs(heights[x][y]-heights[nr][nc]), diff);
                        if(newEffort<grid[nr][nc]){
                            grid[nr][nc]=newEffort;
                            pq.push({newEffort,{nr,nc}});
                        }
                    }
                }
            }
        }
        return 0;
    }
};