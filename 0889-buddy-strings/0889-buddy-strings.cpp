class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())return false;

        if(s.size()==0 || s.size()==1)return false;

        if(s==goal){
            set<char>st(s.begin(), s.end());
            if(st.size() != s.size()) return true;
            return false;
        }

        int cnt=0, first=-1, second=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i]){
                cnt++;
                if(first==-1)first=i;
                else if(second==-1)second=i;

                if(cnt>2)return false;
            }
        }
        if(cnt==2){
            if(s[first] == goal[second] && goal[first] == s[second])
               return true;
        }
        return false;
    }
};