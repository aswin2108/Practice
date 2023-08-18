class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>adj[n];
        vector<int>indegree(n, 0);
        for(auto it:roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int curr=indegree[i]+indegree[j];
                for(auto it:adj[i]){
                    if(it==j)curr--;
                }
                ans=max(ans, curr);
            }
        }
        return ans;
    }
};