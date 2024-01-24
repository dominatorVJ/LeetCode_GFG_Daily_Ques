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
     void Solve(TreeNode* root, vector<int>& visited, int& count){
        if(root == NULL)
        return;

        visited[root->val]++;
        Solve(root->left, visited, count);
        Solve(root->right, visited, count);

        if(root->left == NULL && root->right == NULL){
            int oddFreq = 0;
            for(int i=1; i<=9; i++){
                if(visited[i]%2 != 0)
                oddFreq++;
            }

            if(oddFreq <= 1){
                count++;
            }
        }
        visited[root->val]--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> visited(10,0);
        int count = 0;

        Solve(root,visited,count);
        return count;
        
    }
};