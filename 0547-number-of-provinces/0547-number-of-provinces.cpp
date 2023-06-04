class Solution {
private:
    void dfs(vector<bool>&vis, vector<int>adj[],int i){
        vis[i]=true;
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(vis,adj,it);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>adj[isConnected.size()+1];
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        vector<bool>vis(isConnected.size()+1, false);
        int cnt=0;
        for(int i=1;i<vis.size();i++){
            if(!vis[i]){
                cnt++;
                dfs(vis, adj, i);
            }
        }
        return cnt;
    }
};