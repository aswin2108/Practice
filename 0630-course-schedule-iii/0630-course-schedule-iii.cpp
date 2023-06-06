class Solution {
private:
    bool static comp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),comp);

        int time=0;
        priority_queue<int>pq;
        for(auto it:courses){
            time+=it[0];
            pq.push(it[0]);
            if(time>it[1]){
                time-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};