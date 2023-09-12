class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        int cnt=0;
        set<int>st;
        for(auto it:mp){
            if(st.find(it.second)==st.end()){
                st.insert(it.second);
            }
            else{
                while(it.second){
                    it.second--, cnt++;
                    if(st.find(it.second)==st.end()){
                        st.insert(it.second);
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};