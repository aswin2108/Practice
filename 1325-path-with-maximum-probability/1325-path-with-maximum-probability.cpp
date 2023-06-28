class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>>adj[n];

        for(int i=0;i<edges.size();i++){
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
        }

        vector<double>dis(n, 0.0);
        dis[start]=1.0;

        queue<int>q;
        q.push(start);

        while(q.size()){
            int top=q.front();
            q.pop();

            for(auto it:adj[top]){
                int node=it.first;
                double prob=it.second;
                double newProb=prob*dis[top];

                if(newProb > dis[node]){
                    dis[node]=newProb;
                    q.push(node);
                }
            }
        }
        return dis[end];
    }
};