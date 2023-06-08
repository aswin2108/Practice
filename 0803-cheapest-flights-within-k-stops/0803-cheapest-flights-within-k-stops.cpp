class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int, pair<int,int>>>q;

        q.push({0,{0,src}});
        vector<int>vis(n,1e9);
        vis[src]=0;
        while(q.size()){
            auto it=q.front();
            int stop=it.first;
            int price=it.second.first;
            int from=it.second.second;
            q.pop();
            if(stop>k)continue;
            for(auto it:adj[from]){
                int to=it.first;
                int toPrice=it.second;
                if(price+toPrice<vis[to] && stop<=k){
                    q.push({stop+1,{price+toPrice, to}});
                    vis[to]=price+toPrice;
                }
            }
        }
        if(vis[dst]==1e9)return -1;
        return vis[dst];
    }
};