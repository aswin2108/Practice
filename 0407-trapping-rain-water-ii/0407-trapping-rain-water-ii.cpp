class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int r=heightMap.size();
        int c=heightMap[0].size();
        vector<vector<bool>>vis(r, vector<bool>(c, false));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>>pq;  

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0 || j==0 || i==r-1 || j==c-1){
                    pq.push({heightMap[i][j], {i,j}});
                    vis[i][j]=true;
                }
            }
        }

       int vol=0, minBd=0;
       while(pq.size()){
           int currentH=pq.top().first;
           int pr=pq.top().second.first;
           int pc=pq.top().second.second;
           pq.pop();
           minBd=max(currentH, minBd);

           int dr[4]={0,0,1,-1};
           int dc[4]={1,-1,0,0};
           for(int i=0;i<4;i++){
               int nr=pr+dr[i];
               int nc=pc+dc[i];
               if(nr>=0 && nr<r && nc>=0 && nc<c && !vis[nr][nc]){
                   pq.push({heightMap[nr][nc], {nr, nc}});
                   vis[nr][nc]=true;
                   if(heightMap[nr][nc]<minBd)
                       vol+=minBd-heightMap[nr][nc];
               }
           }
       }


       return vol;

    }
};