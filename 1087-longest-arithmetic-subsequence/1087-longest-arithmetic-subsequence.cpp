class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1, vector<int>(1001, 1));

        int ans=1, dif;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                dif=nums[i]-nums[j];
                dp[i][dif+500]=max(dp[i][dif+500], 1+dp[j][dif+500]);
                ans=max(ans, dp[i][dif+500]);
            }
        }
        return ans;
    }
};