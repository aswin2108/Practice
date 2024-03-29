class Solution {
public:
    bool isUgly(int n) {
        if(n<1)return false;

        int num=n, ori=n;

        while(num!=1){
            if(num%2==0)num/=2;
            else if(num%3==0)num/=3;
            else if(num%5==0)num/=5;
            
            if(num==ori)return false;
            ori=num;
        }
        return true;
    }
};