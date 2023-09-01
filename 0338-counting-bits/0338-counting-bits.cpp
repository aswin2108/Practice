class Solution {
    int solve(int n){
        int cnt=0;
        while(n){
            n = n & (n-1);
            cnt++;
        }
        return cnt;
    }
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            ans.push_back(solve(i));
        }
        return ans;
    }
};