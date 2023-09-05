class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1)return 0;
        queue<pair<int,pair<int,int>>>q;
        set<pair<int,int>>vis;
        int allMask=(1<<n) - 1;

        for(int i=0;i<n;i++){
            int mask = 1<<i;
            q.push({i, {0, mask}});
            vis.insert({i, mask});
        }

        while(q.size()){
            auto it = q.front();
            q.pop();
            int val=it.first;
            int dist=it.second.first;
            int mask=it.second.second;

            for(auto node:graph[val]){
                int newMask=(mask | (1<<node));
                
                if(newMask == allMask) return dist+1;
                else if(vis.count({node, newMask})){
                    continue;
                }
                else{
                    vis.insert({node, newMask});
                    q.push({node, {dist+1, newMask}});
                }
            }
        }
        return 0;
    }
};