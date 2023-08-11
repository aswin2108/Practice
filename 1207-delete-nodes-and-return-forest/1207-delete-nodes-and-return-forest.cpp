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
    TreeNode* solve(vector<TreeNode*>&ans, unordered_set<int>&st, TreeNode* root){
        if(root==NULL)return NULL;
        root->left=solve(ans, st, root->left);
        root->right=solve(ans, st, root->right);
        if(st.find(root->val)!=st.end()){
            st.erase(root->val);
            if(root->left)v.push_back(root->left);
            if(root->right)v.push_back(root->right);
            return NULL;
        }
        return root;
    }
public:
vector<TreeNode*>v;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>st;
        for(int i=0;i<to_delete.size();i++){
            st.insert(to_delete[i]);
        }
        if(st.find(root->val)==st.end()){
            v.push_back(root);
        }
        solve(v, st, root);
        return v;
    }
};