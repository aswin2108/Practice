class Solution {
    void req(vector<vector<int>>& requests, int idx, vector<int>&cnt, int nums){
        if(idx==requests.size()){
            for(int i:cnt){
                if(i!=0){
                    return;
                }
            }
            maxi=max(maxi, nums);
            return;
        }
        cnt[requests[idx][0]]--;
        cnt[requests[idx][1]]++;
        req(requests, idx+1, cnt, nums+1);
        cnt[requests[idx][1]]--;
        cnt[requests[idx][0]]++;

        req(requests, idx+1, cnt, nums);
    }
public:
    int maxi=0;
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>cnt(n, 0);
        req(requests, 0, cnt, 0);
        return maxi;
    }
};