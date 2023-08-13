class Solution {
    bool solve(vector<int>&nums, int idx, vector<int>&dp){
        if(idx == nums.size())return true;
        if(dp[idx] != -1)return dp[idx];
        if(idx+1<nums.size() && nums[idx] == nums[idx+1]){
            if(solve(nums, idx+2, dp))return dp[idx] = true;

            if(idx+2<nums.size() && nums[idx+1]==nums[idx+2]){
                if(solve(nums, idx+3, dp))return dp[idx] = true;
            }
        }
        if(idx+2 < nums.size() && nums[idx]+1 == nums[idx+1] && nums[idx+1]+1 == nums[idx+2]){
            if(solve(nums, idx+3, dp))return dp[idx] = true;
        }
        return dp[idx] = false;
    }
public:
    bool validPartition(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};