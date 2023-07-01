class Solution {
    bool isPossible(vector<int>& weights, int days, long long int mid){
        long long int cnt=1, sum=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>mid)return false;
            sum+=weights[i];

            if(sum>mid){
                cnt++;
                sum=weights[i];
            }
        }
        if(cnt<=days)return true;
        return false;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long int lo=1, hi=1e14, ans=0;
        while(lo<=hi){
            long long int mid=lo+(hi-lo)/2;
            if(isPossible(weights, days, mid)){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;   
    }
};