class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0, j=0, n=nums.size(), cnt=0;
        long long pro=1;

        if(k==1)return 0;

        while(j<n){
            pro*=nums[j];
            while(i<n && pro>=k){
                pro/=nums[i];
                i++;
            }
            if(pro<k) cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
};