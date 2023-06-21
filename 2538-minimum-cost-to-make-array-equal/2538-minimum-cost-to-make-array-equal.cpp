class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans=0, sum=0, tot=0, n=nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i], cost[i]});
            sum+=(long long)cost[i];
        }

        sort(v.begin(), v.end());
        long long median, i=0;
        while(tot<(sum+1)/2 && i<n){
            tot+=v[i].second;
            median=v[i].first;
            i++;
        }
        for(int i=0;i<n;i++){
            ans+=(long long)(abs(nums[i]-median)*cost[i]);
        }
        return ans;
    }
};