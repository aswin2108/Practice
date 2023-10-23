class Solution {
public:
    int characterReplacement(string s, int k) {
        map<int,int>mp;
        int ans=0, maxfreq=0;
        int i=0, j=0;
        for(j=0;j<s.size();j++){
            mp[s[j]]++;
            maxfreq=max(maxfreq, mp[s[j]]);

            while(j-i+1 -maxfreq >k){
                mp[s[i]]--;
                i++;
            }
            ans=max(ans, j-i+1);
        }
        return ans;
    }
};