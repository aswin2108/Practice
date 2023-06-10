class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>candies(n, 1);

        for(int i=1;i<n;i++){
            if(ratings[i-1]<ratings[i]){
                candies[i]=candies[i-1]+1;
            }
        }

        int right=1;
        for(int j=n-2;j>=0;j--){
            if(ratings[j]>ratings[j+1]){
                right++;
                candies[j]=max(candies[j], right);
            }
            else
               right=1;
        }

        int sum=0;
        for(int i:candies){
            sum+=i;
        }
        return sum;
    }
};