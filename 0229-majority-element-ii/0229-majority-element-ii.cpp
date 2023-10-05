class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=INT_MAX, num2=INT_MAX, cnt1=0, cnt2=0;
        for(int &i:nums){
            if(num1 == i){
                cnt1++;
            }
            else if(num2 == i){
                cnt2++;
            }
            else if(cnt1 == 0){
                num1 = i;
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                num2 = i;
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        int numC1 = 0, numC2 = 0;
        for(int &i:nums){
            if(num1 == i) numC1++;
            else if(num2 == i) numC2++;
        }
        vector<int>ans;
        if(num1 != INT_MAX && numC1 > nums.size()/3)ans.push_back(num1);
        if(num2 != INT_MAX && numC2 > nums.size()/3)ans.push_back(num2);
        
        return ans;
    }
};