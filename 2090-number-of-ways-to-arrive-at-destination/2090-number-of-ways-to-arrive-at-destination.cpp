class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long, long long>>adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>pq;
        vector<long long>dist(n, LONG_MAX), path(n,0);
        dist[0]=0;
        path[0]=1;
        pq.push({0,0});
        long long mod=1e9+7;
        while(pq.size()){
            long long node=pq.top().second;
            long long distance=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                long long adjNode=it.first;
                long long edgeWeight=it.second;

                if(distance+edgeWeight<dist[adjNode]){
                    dist[adjNode]=(distance+edgeWeight);
                    pq.push({distance+edgeWeight, adjNode});
                    path[adjNode]=path[node];
                }
                else if(distance+edgeWeight==dist[adjNode]){
                    path[adjNode]=(path[adjNode]+path[node])%mod;
                }
            }
        }
        return path[n-1];
    }
};