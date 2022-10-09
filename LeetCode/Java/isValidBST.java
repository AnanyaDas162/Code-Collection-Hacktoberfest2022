class Solution{
public boolean isValidBST(TreeNode root) {
        return isValidBS(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
    
    private boolean isValidBS(TreeNode root, long min, long max){
        if (root == null) // base case - if reached a leaf return true for the logical AND
            return true;
        
        if (root.val <= min || root.val >= max) // if the values are not legal return false
            return false;
			// use recursion to validate the left and right subtrees
        return isValidBS(root.left, min, root.val) && isValidBS(root.right, root.val, max);
    }
}
