class Solution {
private:
    void dfs(unordered_map<int, stack<int>>&adj,  vector<vector<int>> &ans, int st){
        auto& stk=adj[st];
        while(stk.size()){
            int next=stk.top();
            stk.pop();
            dfs(adj, ans, next);
            ans.push_back({st, next});
        }
    }

public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n=pairs.size();
       unordered_map<int, stack<int>> adj;
       adj.reserve(n);
        unordered_map<int, int> in;
        unordered_map<int, int> out;
        in.reserve(n);
		out.reserve(n);
        for(auto it:pairs){
            in[it[1]]++;
            out[it[0]]++;
            adj[it[0]].push(it[1]);
        }
        int st=-1;
        for(auto& it:adj){
            int i=it.first;
            if(out[i] - in[i] == 1){
                st=i;
            }
        }
        
        if(st==-1) st = adj.begin()->first;
        
        vector<vector<int>> ans;
        dfs(adj, ans, st);
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
};