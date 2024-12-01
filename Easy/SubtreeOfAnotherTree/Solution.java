package SubtreeOfAnotherTree;

public class Solution {
   public static void main(String []args){

        TreeNode leftRight= new TreeNode(2);
        TreeNode leftLeft = new TreeNode(1);
        TreeNode right = new TreeNode(5);
        TreeNode left = new TreeNode(4,leftLeft,leftRight);
        TreeNode root = new TreeNode(3,left,right); 

        TreeNode subRootRight= new TreeNode(2);
        TreeNode subRootLeft= new TreeNode(1);
        TreeNode subRoot= new TreeNode(4, subRootLeft, subRootRight);

        System.out.println(isSubtree(root,subRoot));

    } 
    private static boolean isSubtree(TreeNode root, TreeNode subRoot){
        return isSame(root, subRoot) || isSame(root.left, subRoot) || isSame(root.right, subRoot);
    }
    private static boolean isSame(TreeNode root, TreeNode subRoot){
     if(root == null && subRoot == null){
        return true;
     }
     if(root == null || subRoot == null){
        return true;
     }
     if(root.val != subRoot.val){
        return false;
     }
     return isSame(root.left, subRoot.left) && isSame(root.right, subRoot.right); 
    }

}
