package BinaryTreeTilt;

public class Solution {
    private static int totalTilt = 0;
    public static void main(String[] args){
        TreeNode rightR = new TreeNode(2);
        TreeNode rightL = new TreeNode(2);
        TreeNode right = new TreeNode(14,rightL , rightR);        

        TreeNode leftRR = new TreeNode(3);
        TreeNode leftLL = new TreeNode(3);
        TreeNode leftR = new TreeNode(1);
        TreeNode leftL = new TreeNode(1,leftLL ,leftRR);
        TreeNode left = new TreeNode(7,leftL,leftR);
        TreeNode root = new TreeNode(21, left, right);

        System.out.println(findTilt(root));
    } 
    private static int findTilt(TreeNode root){
        if(root == null){
            return 0;
        }
        dfs(root);
        return totalTilt;
    }
    private static int dfs(TreeNode root){
        if(root == null){
            return 0;
        } 
        int left = dfs(root.left);
        int right = dfs(root.right);
        totalTilt+= Math.abs(left-right);
        return root.val + left + right;
    }
}
