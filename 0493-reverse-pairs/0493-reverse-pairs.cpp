class Solution {
private:
    int merge(vector<int>&nums, int lo, int mid, int hi){
        int cnt=0;
        int j=mid+1;
        for(int i=lo;i<=mid;i++){
            while(j<=hi && nums[i]>2LL*nums[j]){
                j++;
            }
            cnt+=(j-(mid+1));
        }
        vector<int>temp;
        int left=lo, right=mid+1;
        while(left<=mid && right<=hi){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left++]);
            }
            else{
                temp.push_back(nums[right++]);
            }
        }
        while(left<=mid){
            temp.push_back(nums[left++]);
        }
        while(right<=hi){
            temp.push_back(nums[right++]);
        }
        for(int i=lo;i<=hi;i++){
            nums[i]=temp[i-lo];
        }
        return cnt;
    }
    int mergeSort(vector<int>&nums, int low, int high){
        if(low>=high)return 0;
        int mid=low+(high-low)/2;
        int ans=mergeSort(nums, low, mid);
        ans+=mergeSort(nums, mid+1, high);
        ans+=merge(nums, low, mid, high);
        return ans;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};