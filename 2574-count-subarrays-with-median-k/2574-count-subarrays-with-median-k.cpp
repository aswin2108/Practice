class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int found = 0, ans = 0, s = 0;
        
        for(int i : nums) {
            if(i == k) found = 1;
            else s += i < k ? -1 : 1;

            if(found) ans += m[s - 1] + m[s];
            else m[s]++; 
        }
        return ans;
    }
};