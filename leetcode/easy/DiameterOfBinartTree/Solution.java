package DiameterOfBinartTree;

public class Solution {
    static int max = 0;
    public static void main(String[] args){
        TreeNode right = new TreeNode(3);
        TreeNode leftRight = new TreeNode(5);
        TreeNode leftLeft = new TreeNode(4);
        TreeNode left  = new TreeNode(2,leftLeft,leftRight);
        TreeNode root = new TreeNode(1,left,right);
        System.out.println(diameterOfBinaryTreeOptimal(root));
    } 

    private static int diameterOfBinaryTreeRecursion(TreeNode root) {
        if(root == null){
            return 0;
        }
        int leftSub = diameterOfBinaryTreeRecursion(root.left);
        int rightSub = diameterOfBinaryTreeRecursion(root.right);
        int diameter = depth(root.left) + depth(root.right);
        diameter = Math.max(diameter,Math.max(leftSub, rightSub));
        return diameter;
    }
    private static int depth(TreeNode root){
        if(root == null){
            return 0;
        }
        int leftSub = depth(root.left);
        int rightSub = depth(root.right);
        return Math.max(leftSub, rightSub)+1;
    }
    private static int diameterOfBinaryTreeOptimal(TreeNode root){
        if(root == null){
            return 0;
        }
        int[] diameter= new int[1];
        height(root, diameter);
        return diameter[0];
    }
    private static int height(TreeNode root, int[] max){
        if(root == null){
            return 0;
        }
        int leftSub = depth(root.left);
        int rightSub = depth(root.right);
        max[0] = Math.max(max[0],leftSub+rightSub);
        return 1+Math.max(leftSub, rightSub);
    }
}
