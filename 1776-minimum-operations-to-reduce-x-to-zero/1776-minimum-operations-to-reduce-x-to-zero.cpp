class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int i=0, j=0;
        int totSum=0, ans=0;
        for(int &i:nums){
            totSum+=i;
        }
        int target=totSum-x, n=nums.size();
        if(target<0)return -1;
        if(target==0)return n;
        long long sum=nums[0];
        while(i<n && j<n){
            while(sum<target && j<n){
                j++;
                sum+=nums[j];
            }
            if(sum == target){
                ans=max(ans, j-i+1);
                sum-=nums[i];
                i++;
            }
            if(sum>target){
                while(sum>target && i<n){
                    sum-=nums[i];
                    i++;
                }
            }
        }
        if(ans==0)return -1;
        return n-ans;
    }
};