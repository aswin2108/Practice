class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<int>adj[V];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>indegre(V,0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegre[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegre[i]==0)q.push(i);
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
        if(ans.size()==V)return ans;
        return {};
    }
};