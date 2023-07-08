class Solution {
    bool solve(vector<int>& nums, int i, int target, vector<vector<int>>&dp){
        if(i<0)return false;
        if(i==0)return (target==nums[0]);

        if(dp[i][target] != -1)return dp[i][target];

        bool notPick=solve(nums, i-1, target, dp);
        bool Pick=false;
        if(nums[i]<=target){
            Pick = solve(nums, i-1, target-nums[i], dp);
        }

        return dp[i][target] = notPick | Pick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        if(sum%2==1)return false;

        vector<vector<int>>dp(nums.size(), vector<int>(sum/2 + 1, -1));

        return solve(nums, nums.size()-1, sum/2, dp);
    }
};