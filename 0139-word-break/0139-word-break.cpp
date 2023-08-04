class Solution {
    int dp[301];
    bool solve(int idx, string &s, set<string>&word){
        if(idx==s.size())return true;
        if(dp[idx]!=-1)return dp[idx];
        string temp="";
        for(int j=idx;j<s.size();j++){
            temp+=s[j];
            if(word.find(temp) != word.end()){
                if(solve(j+1, s, word))return dp[idx]=1;
            }
        }
        return dp[idx]=0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        memset(dp,  -1,sizeof dp);
        for(auto &it:wordDict)st.insert(it);
        return solve(0, s, st);
    }
};