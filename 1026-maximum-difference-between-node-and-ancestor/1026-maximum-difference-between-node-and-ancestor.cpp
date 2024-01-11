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
    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL) return 0;
        
        return maxDiff(root,root->val,root->val);
    }
    int maxDiff(TreeNode* root,int mx,int mn){
        //base case
        if(root == NULL) return mx-mn;
        mx=max(root->val,mx);
        mn = min(root->val,mn);
        int left = maxDiff(root->left,mx,mn);
        int right = maxDiff(root->right,mx,mn);
        
        return max(left,right);
    }
};