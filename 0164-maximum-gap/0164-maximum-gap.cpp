
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2)return 0;
        long ans=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(ans<nums[i]-nums[i-1])
                ans=nums[i]-nums[i-1];
        }
        return ans;
    }
};