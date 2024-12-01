package SumOfLeftLeaves;

public class Solution {
    private static int sum = 0;
    public static void main(String[] args){
        
        TreeNode rightR = new TreeNode(7); 
        TreeNode rightL = new TreeNode(15); 
        TreeNode right = new TreeNode(20,rightL,rightR);
        TreeNode left = new TreeNode(9);
        TreeNode root = new TreeNode(3,left,right);
        System.out.println(sumofleftleaves(root));
    }
    private static int sumofleftleaves(TreeNode root){
        sumofleftleavesHelper(root);
        return sum;
    }
    private static void  sumofleftleavesHelper(TreeNode root){
        if(root == null){
            return;
        }
        if (root.left != null && root.right != null) {
            TreeNode temp = root.left;
            if (temp.right == null && temp.left == null) {
                sum = sum + temp.val;
            }
            
        }
        sumofleftleavesHelper(root.left);
        sumofleftleavesHelper(root.right);
    }
}
