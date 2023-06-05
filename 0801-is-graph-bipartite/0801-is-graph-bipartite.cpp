class Solution {
private:
   bool dfs(vector<vector<int>>& graph, vector<int>&clr, int node){
       for(auto it:graph[node]){
           if(clr[it]==-1){
               clr[it]=!clr[node];
               if(dfs(graph, clr, it)==false)return false;
           }
           else if(clr[it]==clr[node])return false;
       }
       return true;
   }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>clr(n,-1);
        for(int i=0;i<n;i++){
            if(clr[i]==-1){
                if(dfs(graph,clr,i)==false)return false;
            }
        }
        return true;
    }
};