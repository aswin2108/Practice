class Solution {
    void dfs(vector<int>adj[], vector<bool>&vis, int node, vector<int>&compNodes){
        if(vis[node])return;
        vis[node]=true;
        compNodes.push_back(node);
        for(auto it:adj[node]){
            dfs(adj, vis, it, compNodes);
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>dvis(n, false), bvis(n, false);
        int ans=0;
        set<pair<int,int>>s;
        for(auto it:edges){
            s.insert({it[0], it[1]});
            s.insert({it[1], it[0]});
        }
        for(int i=0;i<n;i++){
            if(!dvis[i]){
                vector<int>compNodes;
                dfs(adj, dvis, i, compNodes);
                bool present=true;
                for(int j=0;j<compNodes.size();j++){
                    for(int k=j+1;k<compNodes.size();k++){
                        if(s.find({compNodes[j], compNodes[k]})==s.end()){
                            present=false;
                            break;
                        }
                    }
                }
                if(present)ans++;
            }
        }
        return ans;
    }
};