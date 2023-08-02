class Solution {
    void calculate(int index, vector<int>& nums, vector<vector<int>>&v){
        if(index==nums.size()){
            vector<int>temp;
            for(int i=0;i<nums.size();i++){
                temp.push_back(nums[i]);
            }
            v.push_back(temp);
            return;
        }

        for(int i=index; i<nums.size();i++){
            swap(nums[i],nums[index]);
            calculate(index+1, nums, v);
            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>v;
        calculate(0, nums, v);
        return v;
    }
};