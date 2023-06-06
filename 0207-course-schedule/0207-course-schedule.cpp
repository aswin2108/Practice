class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>indegre(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegre[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegre[i]==0)q.push(i);
        }
        vector<int>v;
        while(q.size()){
            int node=q.front();
            q.pop();
            v.push_back(node);

            for(auto it:adj[node]){
                indegre[it]--;
                if(indegre[it]==0)q.push(it);
            }
        }
        if(numCourses==v.size())return true;
        return false;
    }
};