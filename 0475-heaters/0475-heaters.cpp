class Solution {
private:
    bool isPossible(vector<int>& houses, vector<int>& heaters, int rad){
        int i=0,j=0;
        int n=houses.size(), m=heaters.size();
        while(j<n){
            if(i==m){
                return false;
            }
            int l=heaters[i]-rad;
            int r=heaters[i]+rad;

            if(houses[j]<l || r<houses[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return true;
    }
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        sort(houses.begin(),houses.end());

        

        int lo=0, hi=1e9+7;
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isPossible(houses, heaters, mid)){
                hi=mid-1;
                ans=mid;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};