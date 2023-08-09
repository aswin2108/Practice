class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n=nums1.size();
        int s1=0,s2=0;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            s1+=nums1[i], s2+=nums2[i];
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.begin(), v.end());

        vector<int>dp(n+1);
        for(int j=0;j<n;j++){
            for(int i=j+1;i>0;--i){
                dp[i]=max(dp[i], dp[i-1]+i*v[j].first+v[j].second);
            }
        }

        for(int i=0;i<=n;i++){
            if(s2*i+s1-dp[i] <=x) return i;
        }
        return -1;
    }
};