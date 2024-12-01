package SumOfRootToLeafBinaryNumbers;

public class Solution {
    static int sum = 0;
    public static void main(String[] args) {

        TreeNode rightR= new TreeNode(0);
        TreeNode rightL= new TreeNode(1);
        TreeNode right = new TreeNode(1,rightL,rightR);
        TreeNode leftR = new TreeNode(1);
        TreeNode leftL = new TreeNode(0);
        TreeNode left = new TreeNode(0,leftL ,leftR);
        TreeNode root = new TreeNode(1, left , right);
        System.out.println(sumRootLeaf(root));
    }
    private static int sumRootLeaf(TreeNode root){
        if(root == null){
            return 0;
        }
        dfsPreOrder(root,0);
        return sum; 
    }
    private static void dfsPreOrder(TreeNode root, int currNumber){
        if(root == null){
            return; 
        }
        currNumber = (currNumber << 1) | root.val;
        if(root.left == null && root.right == null){
            sum += currNumber;
        }
        dfsPreOrder(root.left, currNumber);
        dfsPreOrder(root.right, currNumber);
    }
}
