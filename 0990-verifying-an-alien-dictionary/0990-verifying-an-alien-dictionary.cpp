class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int>mp;
        for(int i=0;i<order.size();i++){
            mp[order[i]]=i;
        }
        for(int i=0;i<words.size()-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            int l=min(s1.length(),s2.length());
            for(int j=0;j<l;j++){
                cout<<j<<"  "<<s1[j]<<"  "<<s2[j]<<"   "<<mp[s1[j]]<<"  "<<mp[s2[j]]<<endl;
                if(mp[s1[j]]>mp[s2[j]]){
                    return false;
                }
                else if(mp[s1[j]]<mp[s2[j]])break;
                if(j==l-1 && s1.size()>s2.size())return false;

            }
        }
        return true;
    }
};