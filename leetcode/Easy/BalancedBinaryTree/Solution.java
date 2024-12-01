package BalancedBinaryTree;

public class Solution {
    private static boolean result = true;
    public static void main(String []args){
        TreeNode right = new TreeNode(2);
        TreeNode leftLeftRight= new TreeNode(4);
        TreeNode leftLeftLeft = new TreeNode(4);
        TreeNode leftRight = new TreeNode(3);
        TreeNode leftLeft = new TreeNode(3,leftLeftLeft,leftLeftRight);
        TreeNode left= new TreeNode(2,leftLeft,leftRight);
        TreeNode root = new TreeNode(1,left,right);
        System.out.println(isBalanced(root));
    } 
    private static boolean isBalanced(TreeNode root){
        isBalancedHelper(root);
        return result;
    }
    private static int isBalancedHelper(TreeNode root){
        if(root == null){
            return 0;
        }
        int leftHeight = isBalancedHelper(root.left);
        int rightHeight = isBalancedHelper(root.right);
        if(Math.abs(leftHeight-rightHeight) > 1){
            result = false;
        }
        return 1+Math.max(leftHeight, rightHeight);
    }
}
