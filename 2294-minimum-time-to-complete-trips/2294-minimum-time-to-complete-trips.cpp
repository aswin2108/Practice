class Solution {
   bool isPossible(vector<int>& t, int totalTrips, long long int mid){
       long long int trip=0;
       for(int i=0;i<t.size();i++){
           trip+=mid/t[i];
       }
       if(trip>=totalTrips)return true;
       return false;
   }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int lo=1, hi=1e14, ans=0;
        while(lo<=hi){
            long long int mid=lo+(hi-lo)/2;

            if(isPossible(time, totalTrips, mid)){
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