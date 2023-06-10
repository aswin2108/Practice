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
public:
   unordered_map<int,int>mp;
   void dfs(TreeNode* root){
       if(!root)return;
       dfs(root->left);
       mp[root->val]++;
       dfs(root->right);
   }
    vector<int> findMode(TreeNode* root) {
     vector<int>ans;
     dfs(root);   
     int maxf=0;
     for(auto it:mp){
         maxf=max(maxf,it.second);
     }
     for(auto it:mp){
         if(it.second==maxf)ans.push_back(it.first);
     }
     return ans;
    }
};