class Solution {
    private:
    bool dfs(vector<vector<int>>& graph, vector<int> &vis, vector<int> &pathVis, vector<int> &checked, int node){
        vis[node]=1;
        pathVis[node]=1;
        checked[node]=0;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(graph, vis, pathVis, checked, it)==true)return true;
            }
            else if(pathVis[it]==1)return true;
        }
        pathVis[node]=0;
        checked[node]=1;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>pathVis(n,0);
        vector<int>checked(n,0);
        vector<int>ans;
        for(int i=0;i<n;i++){
            dfs(graph, vis, pathVis, checked, i);
        }
        for(int i=0;i<n;i++){
            if(checked[i]==1)
               ans.push_back(i);
        }
        return ans;
    }
};