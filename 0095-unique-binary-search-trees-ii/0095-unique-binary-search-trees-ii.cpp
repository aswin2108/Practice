/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<TreeNode*>solve(int l, int r){
        if(l>r || l<1){
            vector<TreeNode*>v;
            v.push_back(NULL);
            return v;
        }
        if(l==r){
            vector<TreeNode*>v;
            TreeNode* temp=new TreeNode;
            temp->val=l;
            temp->left=NULL;
            temp->right=NULL;
            v.push_back(temp);
            return v;
        }
        vector<TreeNode*>ans;
        for(int i=l;i<=r;i++){
            vector<TreeNode*>lt=solve(l,i-1);
            vector<TreeNode*>rt=solve(i+1,r);
            for(int k=0;k<lt.size();k++){
                for(int j=0;j<rt.size();j++){
                    TreeNode* temp=new TreeNode;
                    temp->val=i;
                    temp->left=lt[k];
                    temp->right=rt[j];
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};