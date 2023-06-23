class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1, -1);
        int ans=0;
        int prev=nums[0], prev2=0;
        for(int i=1;i<nums.size();i++){
            int pick=nums[i];
            if(i>1)pick+=prev2;
            int noPick=0+prev;

            int curri=max(pick, noPick);
            prev2=prev;
            prev=curri;
        }

        return prev;
    }
};