class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long>time(n+1, 0);
        vector<int>ans(n, 0);
        sort(meetings.begin(), meetings.end());

        for(auto it:meetings){
            int start = it[0];
            int end = it[1];
            int minIdx=-1;
            long long minVal=1e18;
            bool flag = false;

            for(int i=0;i<n;i++){
                if(time[i] < minVal){
                    minVal=time[i];
                    minIdx=i;
                }
                if(time[i] <= start){
                    time[i]=end;
                    flag=true;
                    ans[i]++;
                    break;
                }
            }

            if(!flag){
                time[minIdx] += (1LL* (end-start));
                ans[minIdx]++;
            }
        }
        
        int maxFreq = -1, maxFreqRoom = -1;
        for(int i=0;i<n;i++){
            if(maxFreq < ans[i]){
                maxFreq = ans[i];
                maxFreqRoom = i;
            }
        }
        return maxFreqRoom;
    }
};