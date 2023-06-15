class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>v;
        int i=1;
        v.push_back(nums[0]);
        while(i<nums.size()){
            if(nums[i]!=nums[i-1])v.push_back(nums[i]);
            i++;
        }
        nums=v;
        return v.size();
    }
};