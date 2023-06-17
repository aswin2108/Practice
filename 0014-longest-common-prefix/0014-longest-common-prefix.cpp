class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string first=strs[0], last=strs[strs.size()-1], ans="";
        for(int i=0;i<min(first.size(), last.size());i++){
            if(first[i]==last[i])
               ans+=first[i];
            else
               break;
        }
        return ans;
    }
};