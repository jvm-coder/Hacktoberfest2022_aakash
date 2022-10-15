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
    
    public static void func(TreeNode node, List<Integer> path, List<List<Integer>> ans, int target) {
        if(node == null)
            return;
        
        path.add(node.val); 
        
        if(node.val == target && node.left==null && node.right==null)
            ans.add(new ArrayList<Integer>(path));
        
        else {
            func(node.left, path, ans, target-node.val);
            func(node.right, path, ans, target-node.val);
        }
        path.remove(path.size()-1);
    }
    
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        func(root, path, ans, targetSum);
        return ans;
    }
}
