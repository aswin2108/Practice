class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(k==1 || k==weights.size())return 0;

        vector<int>possibilities;
        for(int i=0;i+1<weights.size();i++){
            possibilities.push_back(weights[i]+weights[i+1]);
        }
        sort(possibilities.begin(), possibilities.end());

        long long int mini=0, maxi=0;
        for(int i=0;i<k-1;i++){
            mini+=possibilities[i];
            maxi+=possibilities[weights.size()-2-i];
        }
        return maxi-mini;
    }
};