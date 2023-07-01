class Solution {
    bool isPossible(vector<int>& v, int k, int mid){
        int cnt=0;
        for(int i=0;i<v.size();i++){
            if(v[i]%mid){
                cnt+=(v[i]/mid)+1;
            }
            else{
                cnt+=v[i]/mid;
            }
        }
        if(cnt>k)return true;
        return false;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo=1, hi=1e9, ans=0;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            vector<int> temp=quantities;
            if(isPossible(quantities, n, mid)){
                 lo=mid+1;   
            }
            else{
                ans=mid;
                hi=mid-1;
            }
        }
        return ans;
    }
};