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
    int solve(TreeNode* root, int &ans, int &prev){
        if(root->left)solve(root->left, ans, prev);
        if(prev>=0)ans=min(ans, abs(prev-root->val));
        prev=root->val;
        if(root->right)solve(root->right, ans, prev);
        return ans;
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int ans=INT_MAX, prev=-1;
        return solve(root, ans, prev);
    }
};