class Solution {
    bool isPossible(int n, vector<int>& batteries, long long int mid){
        long long int cnt=0;
        for(int i=0;i<batteries.size();i++){
            cnt+=min(mid, 1LL*batteries[i]);
        }
        if(cnt>=mid*n)return true;
        return false;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long int lo=1, hi=1e14;
        long long int ans=0;
        while(lo<=hi){
            long long int mid=lo+(hi-lo)/2;
            if(isPossible(n, batteries, mid)){
                lo=mid+1;
                ans=mid;
            }
            else{
                hi=mid-1;
            }
        }
        return ans;
    }
};