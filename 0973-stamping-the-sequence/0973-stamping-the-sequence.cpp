class Solution {
private:
    void replace(int idx, string s, string &tar){
        for(int i=idx;i<idx+s.size();i++){
            tar[i]='?';
        }
        return;
    }

    int find(string stamp, string tar){
        int tlen=tar.size();
        int slen=stamp.size();
        for(int i=0;i<=tlen-slen;i++){
            int k=0, flag=0;
            bool change=true;
            for(int j=i; j<i+slen;j++){
                if(tar[j]==stamp[k] ){
                    change=false;
                }
                if(tar[j]!=stamp[k] && tar[j]!='?'){
                    flag=1;
                    break;
                }
                k++;
            }
            if(flag==0 && !change){
                return i;
            }
        }
        return -1;
    }
    
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int>ans;
        int tlen=target.size();
        int slen=stamp.size();
        string revTar(tlen, '?');
        string currTar=target;

        while(currTar!=revTar){
            int idx=find(stamp, currTar);

            if(idx<0){
                return {};
            }
            else{
                replace(idx, stamp, currTar);
                ans.push_back(idx);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};