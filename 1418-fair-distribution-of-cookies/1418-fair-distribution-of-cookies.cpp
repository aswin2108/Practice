class Solution {
private:
    bool isPossible(vector<int>& cookies, int k, int mid){
        int noOfKids=1;
        int sum=0;
        for(int i=0;i<cookies.size();i++){
            if(cookies[i]>mid)return false;
            sum+=cookies[i];
            if(sum>mid){
                noOfKids++;
                sum=cookies[i];
            }
        }
        if(noOfKids>k)return false;
        return true;
    }
    int bs(vector<int>& cookies, int k, long long int hi){
        long long int lo=0, ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(isPossible(cookies, k, mid)){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        sort(cookies.begin(), cookies.end());
        long long int hi=accumulate(cookies.begin(),cookies.end(),0);
        int ans=INT_MAX;
        do{
            ans=min(ans, bs(cookies, k, hi));
        }while(next_permutation(cookies.begin(), cookies.end()));

        return ans;
    }
};