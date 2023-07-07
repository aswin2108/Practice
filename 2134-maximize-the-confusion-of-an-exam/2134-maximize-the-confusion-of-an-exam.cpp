class Solution {
    int solve(string s, int k, char flag){
        int j=0, cnt=0, ans=INT_MIN;
        for(int i=0;i<s.size();i++){
            if(s[i] == flag){
                cnt++;
            }
            while(cnt>k){
                if(s[j] == flag){
                    cnt--;
                }
                j++;
            }
            ans=max(ans, i-j+1);
        }
        return ans;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans1=solve(answerKey, k, 'T');
        int ans2=solve(answerKey, k, 'F');

        return max(ans1, ans2);
    }
};