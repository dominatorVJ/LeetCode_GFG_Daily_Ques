/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
    int cnt = 0;
    int averageOfSubtree(TreeNode *root)
    {
        function(root);
        return cnt;
    }
    pair<int, int> function(TreeNode *root)
    {
        if (root == NULL)
        {
            return {0,0};
        }
        pair<int, int> left = function(root->left);
        pair<int, int> right = function(root->right);
        int sum = root->val + left.first + right.first;
        int count = 1 + left.second + right.second;

        if (sum / count == root->val) cnt++;

        return {
            sum,
            count
        };
    }
};