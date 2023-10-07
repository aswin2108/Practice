class Solution {
    int N,M,K, mod=1e9+7;
    int dp[51][51][101];
    int solve(int idx, int cost, int maxVal){
        if(idx==N){
            if(cost==K)return 1;
            return 0;
        }

        if(dp[idx][cost][maxVal] != -1)return dp[idx][cost][maxVal];
        
        int res=0;
        for(int i=1;i<=M;i++){
            if(i>maxVal){
                res=(res+solve(idx+1, cost+1, i))%mod;
            }
            else{
                res=(res+solve(idx+1, cost, maxVal))%mod;
            }
        }
        return dp[idx][cost][maxVal]=res%mod;
    }
public:
    int numOfArrays(int n, int m, int k) {
        N=n, M=m, K=k;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0);
    }
};