class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ans=0;

        if(startPos[0] < homePos[0]){
            while(startPos[0] < homePos[0]){
                startPos[0]++;
                ans += rowCosts[startPos[0]];
            }
        }
        else{
            while(startPos[0] > homePos[0]){
                startPos[0]--;
                ans += rowCosts[startPos[0]];
            }
        }

        if(startPos[1] < homePos[1]){
            while(startPos[1] < homePos[1]){
                startPos[1]++;
                ans += colCosts[startPos[1]];
            }
        }
        else{
            while(startPos[1] > homePos[1]){
                startPos[1]--;
                ans += colCosts[startPos[1]];
            }
        }
        return ans;
    }
};