class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>>mp;
        int n=nums.size();
        int ans=n-1;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        for(auto it:mp){
            vector<int>idx=it.second;

            int dist= (n-1-idx[idx.size()-1]) + idx[0];

            for(int j=1;j<idx.size();j++){
                dist=max(dist, idx[j]-idx[j-1]-1);
            }
            ans=min(ans, dist);
        }
        return (ans+1)/2;
    }
};