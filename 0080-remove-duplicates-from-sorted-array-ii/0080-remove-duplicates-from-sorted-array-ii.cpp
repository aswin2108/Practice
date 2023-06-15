class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>v;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]<3){
                v.push_back(nums[i]);
            }
        }
        nums=v;
        return v.size();
    }
};