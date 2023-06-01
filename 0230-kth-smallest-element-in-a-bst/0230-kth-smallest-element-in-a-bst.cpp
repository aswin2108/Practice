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
    int ans, cnt=0;
    void solve(TreeNode* root, int k){
        if(root==NULL)return;
        solve(root->left, k);
        cnt++;
        if(cnt==k)ans=root->val;
        solve(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        solve(root,k);
        return ans;
    }
};