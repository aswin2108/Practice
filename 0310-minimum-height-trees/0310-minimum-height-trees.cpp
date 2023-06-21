class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return{0};

        vector<unordered_set<int>>adj(n);
        for (int i = 0; i < n; ++i) adj[i] = unordered_set<int>();

        for(auto it:edges){
            adj[it[0]].insert(it[1]);
            adj[it[1]].insert(it[0]);
        }
        
        vector<int>leaves;
        for(int i=0;i<n;i++){
            if(adj[i].size()==1){
                leaves.push_back(i);
            }
        }
        while(n>2){
            n-=leaves.size();
            vector<int>newLeaves;
            for(int it:leaves){
                int j=*adj[it].begin();
                adj[j].erase(it);
                if(adj[j].size()==1)newLeaves.push_back(j);
            }
            leaves=newLeaves;
        }
        return leaves;
    }
};