class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        int no=x;
        unsigned long long temp=0;
        while(no){
            temp=(temp*10)+(no%10);
            no/=10;
        }
        return temp==x;
    }
};