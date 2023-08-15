class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector<int>r(n),c(m);
        vector<vector<int>>temp(n, vector<int>(m));
        unordered_map<int, vector<vector<int>>>mp;
        set<int, greater<int>>st;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[mat[i][j]].push_back({i, j});
                st.insert(mat[i][j]);
            }
        }

        for(auto &s:st){
            for(auto it:mp[s]){
                int i=it[0], j=it[1];
                temp[i][j]=max(r[i], c[j])+1;
            }
            for(auto it:mp[s]){
                int i=it[0], j=it[1];
                r[i]=max(r[i], temp[i][j]);
                c[j]=max(c[j], temp[i][j]);
            }
        }
        return max(*max_element(r.begin(), r.end()), *max_element(c.begin(), c.end()));
    }
};