package InvertBinaryTree;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    public static void main(String []args){

        TreeNode rightRight= new TreeNode(9);
        TreeNode rightLeft= new TreeNode(6);
        TreeNode right = new TreeNode(7,rightLeft,rightRight);
        TreeNode leftRight= new TreeNode(3);
        TreeNode leftLeft = new TreeNode(1);
        TreeNode left= new TreeNode(2,leftLeft,leftRight);
        TreeNode root = new TreeNode(4, left, right);

        bfs(root);
        bfs(invertBinaryTree(root));
    } 
    private static void bfs(TreeNode root){
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        System.out.println();
        while(!q.isEmpty()){
            TreeNode temp = q.poll();
            if(temp ==null) return;
            System.out.print(temp.val + " --->");
            q.offer(temp.left);
            q.offer(temp.right);
        }
    }
    private static TreeNode invertBinaryTree(TreeNode root){
        if(root == null){
            return null;
        }
        TreeNode temp = root.left;
        root.left= root.right;
        root.right= temp;
        invertBinaryTree(root.left);
        invertBinaryTree(root.right);
        return root; 
    }
}
