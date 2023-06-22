class Solution {
private:
    void dfs(vector<int>adj[], vector<bool>&vis, int node){
        if(vis[node])return;
        vis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(adj, vis, it);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<rooms[i].size();j++){
                adj[i].push_back(rooms[i][j]);
            }
        }
        
        vector<bool>vis(n, false);
        
        dfs(adj, vis, 0);      

        for(int i=0;i<n;i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};