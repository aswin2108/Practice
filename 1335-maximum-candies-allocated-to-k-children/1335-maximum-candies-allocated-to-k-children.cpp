class Solution {
    bool isPossible(vector<int>& candies, long long k, long long int mid){
        long long int pile=0;
        for(int i:candies){
            pile+=i/mid;
        }
        if(pile>=k)return true;
        else return false;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long int lo=1, hi=1e14;
        int ans=0;
        while(lo<=hi){
            long long int mid=lo+(hi-lo)/2;
            if(isPossible(candies, k, mid)){
                ans=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return ans;
    }
};