/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
    int checkMatch(string &a, string &b){
        int cnt=0;
        for(int i=0;i<6;i++){
            if(a[i] == b[i]){
                cnt++;
            }
        }
        return cnt;
    }
public:
    void findSecretWord(vector<string>& words, Master& master) {
        // master.guess(*reinterpret_cast<string *>(&master));
        for(int i=0, match=0; i<30 && match < 6; i++){
            string trial = words[words.size()/2];
            match = master.guess(trial);
            vector<string>candidates;
            for(string word:words){
                if(checkMatch(trial, word) == match){
                    candidates.push_back(word);
                }
            }
            words = candidates;
        }
    }
};