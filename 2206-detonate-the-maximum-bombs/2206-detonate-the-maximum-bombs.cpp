class Solution {
private:
    void dfs(vector<long long>adj[], vector<bool>&vis, int &n, int &cnt, int idx){
        if(vis[idx])return;
        vis[idx]=true;
        cnt++;
        for(auto it: adj[idx]){
            dfs(adj, vis, n, cnt, it);
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<long long>adj[n];

        for(int i=0;i<n;i++){
            long long x1=bombs[i][0];
            long long y1=bombs[i][1];
            long long r1=bombs[i][2];

            for(int j=0;j<n;j++){
                if(i!=j){
                    long long x=abs(bombs[j][0]-x1);
                    long long y=abs(bombs[j][1]-y1);
                    if(x*x+y*y <= r1*r1){
                        adj[i].push_back(j);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            vector<bool>vis(n, false);
            int cnt=0;
            dfs(adj, vis, n, cnt, i);
            ans=max(ans, cnt);
        }
        return ans;
    }
};