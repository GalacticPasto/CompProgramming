package DiameterOfBinaryTree;

import java.util.Stack;

public class Solution {
    private static int diameter = 0;
    public static void main(String []args){
        TreeNode right = new TreeNode(3);
        TreeNode leftRight = new TreeNode(5);
        TreeNode leftLeft = new TreeNode(4);
        TreeNode left = new TreeNode(2,leftLeft,leftRight);
        TreeNode root = new TreeNode(1,left,right);
        System.out.println(diameterOfBinaryTreeRecursive(root));
        diameterOfBinaryTree(root);
    } 
    private static int diameterOfBinaryTree(TreeNode root){
        if(root == null) return 0;
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root); 
        int diameter = 0 ;
        while(!stack.isEmpty()){
            TreeNode temp = stack.pop();
            if(temp.right == null && temp.left == null){
                return diameter++;
            }
            if(temp.left != null){

            }
        }
        return 0;
    }
    private static int diameterOfBinaryTreeRecursive(TreeNode root){
        if(root == null) return diameter;
        diameter++;
        diameterOfBinaryTreeRecursive(root.left);
        diameterOfBinaryTreeRecursive(root.right);
        return diameter;
    }
}

