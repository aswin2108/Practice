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
    int heightNode(TreeNode* root){
        if(root==NULL)return 0;

        int leftH=heightNode(root->left);
        int rightH=heightNode(root->right);

        l[root->val]=leftH;
        r[root->val]=rightH;

        return max(leftH, rightH)+1;
    }
    void solve(TreeNode* root, int maxa, int depth){
        if(root==NULL)return;

        h[root->val] = maxa;

        solve(root->left, max(maxa, depth+r[root->val]), depth+1);
        solve(root->right, max(maxa, depth+l[root->val]), depth+1);
    }
public:
    unordered_map<int,int>l,r,h;
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        heightNode(root);

        solve(root->left, r[root->val], 1);
        solve(root->right, l[root->val], 1);

        vector<int>ans;
        for(int &i:queries){
            ans.push_back(h[i]);
        }
        return ans;
    }
};