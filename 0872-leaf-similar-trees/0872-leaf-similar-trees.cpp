/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        bool leafSimilar(TreeNode *root1, TreeNode *root2)
        {
            vector<int> v1 = extractLeafs(root1);
            vector<int> v2 = extractLeafs(root2);
            return v1 == v2;
        }
    vector<int> extractLeafs(TreeNode *root)
    {
        vector<int> res;
        extractLeafsHelp(root, res);
        return res;
    }
    void extractLeafsHelp(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr) return;
        if (root->left == NULL && root->right == NULL)
        {
            res.push_back(root->val);
            return;
        }
        extractLeafsHelp(root->left, res);
        extractLeafsHelp(root->right, res);
    }
};