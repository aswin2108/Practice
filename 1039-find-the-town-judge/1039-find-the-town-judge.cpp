class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0 && n==1)return 1;

        vector<int>cnt(n+1, 0);
        for(auto it: trust){
            cnt[it[0]]--;
            cnt[it[1]]++;
        }

        for(int i=0;i<cnt.size();i++){
            if(cnt[i]==n-1)
               return i;
        }
        return -1;
    }
};