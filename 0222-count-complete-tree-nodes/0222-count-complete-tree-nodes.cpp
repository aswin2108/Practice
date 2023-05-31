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
    int rightSubTreeHeight(TreeNode* root){
       int h=0;
       while(root){
           h++;
           root=root->right;
       }
       return h;
    }
    int leftSubTreeHeight(TreeNode* root){
       int h=0;
       while(root){
           h++;
           root=root->left;
       }
       return h;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int rightHeight=rightSubTreeHeight(root);
        int leftHeight=leftSubTreeHeight(root);
        if(rightHeight==leftHeight) return (1<<leftHeight)-1;

        return 1+countNodes(root->left)+countNodes(root->right);
    }
};