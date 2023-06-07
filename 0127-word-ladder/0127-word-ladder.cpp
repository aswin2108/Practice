class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord, 1});
        st.erase(beginWord);

        while(q.size()){
            string word=q.front().first;
            int level=q.front().second;
            q.pop();
            if(word==endWord)return level;

            for(int i=0;i<word.size();i++){
                for(char ch='a';ch<='z';ch++){
                    string temp=word;
                    temp[i]=ch;
                    if(st.find(temp)!=st.end()){
                        q.push({temp,level+1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};