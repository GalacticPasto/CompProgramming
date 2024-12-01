package PathSum;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    private static int sum = 0;
    public static void main(String []args){

        TreeNode rightRightRight = new TreeNode(1);
        TreeNode rightRight = new TreeNode(4,null,rightRightRight);
        TreeNode rightLeft = new TreeNode(13);
        TreeNode right = new TreeNode(8,rightLeft,rightRight);
        TreeNode leftLeftRight = new TreeNode(2);
        TreeNode leftLeftLeft = new TreeNode(7);
        TreeNode leftLeft = new TreeNode(11, leftLeftLeft, leftLeftRight);
        TreeNode left = new TreeNode(4, leftLeft, null);
        TreeNode root = new TreeNode(5, left, right);
        bfs(root);
        System.out.println(hasPathSum(root, 22));

    }
    public static boolean hasPathSum(TreeNode root, int targetSum){
        if(root == null){
            return false;
        }
        targetSum= targetSum-root.val;
        if(root.left == null && root.right == null){
            if(sum == 0){
                return true;
            }
            else{
                return false;
            }
        }
        return (hasPathSum(root.left, targetSum) || hasPathSum(root.right, targetSum));
    }
    private static void bfs(TreeNode root){
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty()){
            TreeNode temp = q.poll();
            if(temp == null){
            System.out.print("null " );     
            continue;
            }
            System.out.print(temp.val + " ");
            q.offer(temp.left);
            q.offer(temp.right);
        }
        System.out.println();
    }
}
