/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int rangeSumBST(TreeNode root, int d1, int d2) {
        int sum = 0;
        if(root == null){
            return 0;
        }
        if(d1<root.val && d2<root.val){
            return rangeSumBST(root.left,d1,d2);
        }else if(d1>root.val && d2>root.val){
            return rangeSumBST(root.right,d1,d2);
        }else{          
            sum+=root.val+rangeSumBST(root.left,d1,d2)+rangeSumBST(root.right,d1,d2); 
        } 
        return sum;
    }
}