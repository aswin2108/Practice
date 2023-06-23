class Solution {
    // int solve(vector<int>& nums, int n, vector<int>&dp){
    //     if(n==nums.size()-1)return nums[nums.size()-1];
    //     if(n>nums.size()-1)return 0;
        
    //     if(dp[n]!=-1)return dp[n];

    //     int pick=nums[n]+dp[n+2]nums, n-2, dp);
    //     int noPick=0+solve(nums, n-1, dp);
    //     return dp[n]=max(pick, noPick);
    // }
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1, -1);
        int ans=0;
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            int pick=nums[i];
            if(i>1)pick+=dp[i-2];
            int noPick=0+dp[i-1];
            dp[i]=max(pick, noPick);
        }

        return dp[nums.size()-1];
    }
};