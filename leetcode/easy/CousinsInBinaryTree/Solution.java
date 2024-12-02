package CousinsInBinaryTree;

public class Solution {
    public static void main(String[] args){
        TreeNode rightR = new TreeNode(5);
        TreeNode leftL = new TreeNode(4); 
        TreeNode right = new TreeNode(3,null,rightR);
        TreeNode left = new TreeNode(2,null,leftL);
        TreeNode root = new TreeNode(1,left,right);

        System.out.println(isCousins(root,5,4));
    } 
    private static boolean isCousins(TreeNode root , int x , int y){

        return false;     
    }
}

