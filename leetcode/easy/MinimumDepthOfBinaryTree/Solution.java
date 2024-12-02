package MinimumDepthOfBinaryTree;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    public static void main(String[] args){

        TreeNode leftLR = new TreeNode(5);
        TreeNode leftLL = new TreeNode(4);
        TreeNode left = new TreeNode(2,leftLL,leftLR);
        TreeNode right= new TreeNode(3);
        TreeNode root = new TreeNode(2,left,right);
        System.out.println(minDepthBFS(root));
    } 
    private static int minDepth(TreeNode root){
        if(root == null){
            return 0;
        }
        int left = minDepth(root.left);
        int right = minDepth(root.right);
        if(left == 0 && right != 0){
            return 1+right;        
        }
        if(right == 0 && left!= 0){
            return 1+left;        
        }
        return 1+Math.min(left, right);
    }

    private static int minDepthBFS(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        TreeNode temp = root;
        int depth = 1;
        while (!q.isEmpty()) {
            int size = q.size();
            while (size > 0) {
                size--;
                temp = q.poll();
                if (temp == null) {
                    continue;
                }
                if (temp.left == null && temp.right == null) {
                    return depth;
                }
                q.offer(temp.left);
                q.offer(temp.right);
            }
            depth++;
        }
        return depth;
    }
}
