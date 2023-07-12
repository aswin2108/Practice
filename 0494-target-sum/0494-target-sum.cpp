class Solution {
    int solve(vector<int>& nums, int n, int target, int cur){
        if(n==0){
            if(nums[0]==0 && cur==target)return 2;
            else if(target==cur+nums[0] || target==cur-nums[0])return 1;
            return 0;
        }

        int plus=solve(nums, n-1, target, cur+nums[n]);
        int minus=solve(nums, n-1, target, cur-nums[n]);

        return plus+minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(nums, n-1, target, 0);
    }
};