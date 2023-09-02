class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int>dp(n+1, n);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(string st:dictionary){
                if(s.substr(i, st.size()) == st){
                    dp[i+st.size()] = min(dp[i], dp[i+st.size()]);
                }
            }
            dp[i+1] = min(dp[i+1], dp[i]+1);
        }
        return dp.back();
    }
};