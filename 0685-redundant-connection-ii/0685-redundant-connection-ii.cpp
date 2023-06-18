class DisjointSet{
        vector<int>parent, size;
    public:
         DisjointSet(int n){
             parent.resize(n+1);
             size.resize(n+1, 1);
             for(int i=0;i<=n;i++){
                 parent[i]=i;
             }
         }
         
         int findUPar(int node){
             if(node==parent[node])
                return node;
             return parent[node]=findUPar(parent[node]);
         }
         
         void unionBySize(int u, int v){
             int ulp_u=findUPar(u);
             int ulp_v=findUPar(v);
             if(ulp_v==ulp_u) return;
             
             if(size[ulp_u]<size[ulp_v]){
                 parent[ulp_u]=ulp_v;
                 size[ulp_v]+=size[ulp_u];
             }
             else{
                 parent[ulp_v]=ulp_u;
                 size[ulp_u]+=size[ulp_v];
             }
         }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=0;
        for(int i=0; i<edges.size(); i++){
            n=max(n, edges[i][0]);
            n=max(n, edges[i][1]);
        }
        DisjointSet ds(n);
        vector<int>indegre(edges.size()+1 , -1);
        int bl1=-1, bl2=-1;
        

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            if(indegre[v]==-1){
                indegre[v]=i;
            }else{
                bl1=i;
                bl2=indegre[v];
                break;
            }
        }
        if(bl1==-1){
            int est, eend;
            for(auto it:edges){
                if(ds.findUPar(it[0]) == ds.findUPar(it[1])){
                    est=it[0], eend=it[1];
                }
                else{
                    ds.unionBySize(it[0], it[1]);
                }
            }
            return {est, eend};
        }
        else{
            for(int i=0;i<edges.size(); i++){
                if(i!=bl1 && ds.findUPar(edges[i][0]) == ds.findUPar(edges[i][1])){
                    return edges[bl2];
                }
                else if(i!=bl1 && (ds.findUPar(edges[i][0]) != ds.findUPar(edges[i][1]))){
                    ds.unionBySize(edges[i][0], edges[i][1]);
                }
            }
            return edges[bl1];
        }
        return {-1,-1};
    }
};