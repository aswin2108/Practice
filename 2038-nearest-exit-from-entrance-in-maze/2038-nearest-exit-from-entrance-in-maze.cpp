class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int cnt=0;
        int n=maze.size(), m=maze[0].size();
        queue<pair<int,int>>q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        // vector<vector<bool>>vis(n, vector<bool>(m, false));
        while(q.size()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                int r=it.first, c=it.second;
                
                if((r==0 || r==n-1 || c==0 || c==m-1) && !(r==entrance[0] && c==entrance[1])){
                    return cnt;
                }
                int dr[4]={-1, 1, 0, 0};
                int dc[4]={0, 0, 1, -1};
                for(int j=0;j<4;j++){
                    int nr=r+dr[j];
                    int nc=c+dc[j];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && maze[nr][nc]=='.'){
                        maze[nr][nc]='+';
                        q.push({nr, nc});
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};