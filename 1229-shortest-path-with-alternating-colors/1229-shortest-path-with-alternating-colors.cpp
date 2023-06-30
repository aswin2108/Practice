class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<multiset<int>>redChild(n), blueChild(n);
        for(auto it:redEdges){
            redChild[it[0]].insert(it[1]);
        }
        for(auto it:blueEdges){
            blueChild[it[0]].insert(it[1]);
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            vector<multiset<int>>blue=blueChild, red=redChild;
            queue<pair<char, int>>q;
            q.push({'n', 0});
            int cnt=0;
            while(q.size()){
                int size=q.size();
                bool isBreak=false;
                for(int j=0;j<size;j++){
                    auto x=q.front();
                    q.pop();

                    if(x.second == i){
                        ans.push_back(cnt);
                        isBreak=true;
                        break;
                    }
                    if(x.first=='n'){
                        for(auto it:blue[x.second]){
                            q.push({'b', it});
                            auto erase=blue[x.second].find(it);
                            blue[x.second].erase(erase);
                        }

                        for(auto it: red[x.second]){
                            q.push({'r', it});
                            auto erase=red[x.second].find(it);
                            red[x.second].erase(erase);
                        }
                    }
                    else if(x.first=='b'){
                        for(auto it:red[x.second]){
                            q.push({'r', it});
                            auto erase=red[x.second].find(it);
                            red[x.second].erase(erase);
                        }
                    }
                    else if(x.first=='r'){
                        for(auto it:blue[x.second]){
                            q.push({'b', it});
                            auto erase=blue[x.second].find(it);
                            blue[x.second].erase(erase);
                        }
                    }

                }
                if(isBreak){
                    break;
                }
                cnt++;
            }
            if(i==ans.size()){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};