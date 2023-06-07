class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        vector<int>indegre(n,0);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
                indegre[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegre[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(q.size()){
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto it:adj[node]){
                indegre[it]--;
                if(indegre[it]==0)q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};