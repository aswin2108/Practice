class Solution {
public:
    vector<string>ans;
    map<int, string>mp;

    void solve(string input, string output, int i){
        if(input.size()==i){
            ans.push_back(output);
            return;
        }
        for(char x:mp[input[i]-'0']){
            output.push_back(x);
            solve(input, output, i+1);
            output.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="")return {};
         mp[2]="abc";
         mp[3]="def";
         mp[4]="ghi";
         mp[5]="jkl";
         mp[6]="mno";
         mp[7]="pqrs";
         mp[8]="tuv";
         mp[9]="wxyz";

        solve(digits, "", 0);
        return ans;
    }
};