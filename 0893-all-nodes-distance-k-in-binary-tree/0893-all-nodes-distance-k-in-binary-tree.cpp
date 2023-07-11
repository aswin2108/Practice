/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void track(TreeNode *root, unordered_map<TreeNode*, TreeNode*>&mp){
        
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            TreeNode* n=q.front();
            q.pop();
            if(n->left){
                mp[n->left]=n;
                q.push(n->left);
            }
            if(n->right){
                mp[n->right]=n;
                q.push(n->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>mp;
        track(root, mp);

        unordered_map<TreeNode*, bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int currLevel=0;
        while(q.size()){
            int size=q.size();
            if(currLevel++==k)break;
            for(int i=0;i<size;i++){
                TreeNode* n=q.front();
                q.pop();
                if(n->left && !visited[n->left]){
                    q.push(n->left);
                    visited[n->left]=true;
                }
                if(n->right && !visited[n->right]){
                    q.push(n->right);
                    visited[n->right]=true;
                }
                if(mp[n] && !visited[mp[n]]){
                    q.push(mp[n]);
                    visited[mp[n]]=true;
                }
            }
        }
        vector<int>ans;
        while(q.size()){
            TreeNode* temp=q.front();q.pop();
            ans.push_back(temp->val);
        }
        return ans;
    }
};