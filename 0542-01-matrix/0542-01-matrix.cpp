class Solution {
    bool isPossible(int i,int j, int n,int m){
        return (i<0 || j<0 || i>=n || j>=m) ? false : true;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>>ans(n, vector<int>(m, -1));
        queue<pair<int, int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};

        while(q.size()){
            int i=q.front().first;
            int j=q.front().second;

            for(int k=0;k<4;k++){
                int nr=i+dr[k];
                int nc=j+dc[k];
                if(isPossible(nr,nc,n,m) && ans[nr][nc]==-1){
                    ans[nr][nc] = 1+ans[i][j];
                    q.push({nr,nc});
                }
            }
            q.pop();
        }
        return ans;
    }
};