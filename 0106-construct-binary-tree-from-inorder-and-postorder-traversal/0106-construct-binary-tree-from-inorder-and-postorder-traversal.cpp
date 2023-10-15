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
        unordered_map<int, int> map;
    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        for (int i = 0; i < n; i++)
        {
            map.insert({ inorder[i],
                i });
        }
        return buildHelp(inorder, postorder, 0, n - 1, n - 1);
    }
    TreeNode* buildHelp(vector<int> &inorder, vector<int> &postorder, int st_in, int end_in, int end_post)
    {

        if (st_in > end_in)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[end_post]);

        int ind = map[postorder[end_post]];
        int cnt_left = ind - st_in;
        int cnt_right = end_in - ind;
        root->left = buildHelp(inorder, postorder, st_in, ind - 1, end_post - cnt_right - 1);
        root->right = buildHelp(inorder, postorder, ind + 1, end_in, end_post - 1);

        return root;
    }
};