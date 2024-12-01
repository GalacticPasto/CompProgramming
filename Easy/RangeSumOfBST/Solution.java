package RangeSumOfBST;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    public static void main (String []args){

        TreeNode rightRight = new TreeNode(18);
        TreeNode right = new TreeNode(15,null,rightRight);
        TreeNode leftRight = new TreeNode(7);
        TreeNode leftLeft = new TreeNode(3);
        TreeNode left = new TreeNode(5,leftLeft,leftRight);
        TreeNode root = new TreeNode(10, left, right);
        
        System.out.println(rangeSumOfBSTRecursive(root, 7,15));
    }
    private static int rangeSumOfBST(TreeNode root,int low , int high){
        int sum = 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty()){
            TreeNode temp =q.poll();
            if(temp == null || temp.val > high) continue;
            if(temp.val >= low && temp.val <= high){
                sum = sum + temp.val;
            }
            q.offer(temp.left);
            q.offer(temp.right);
        }
        return sum;
    }  
    private static int rangeSumOfBSTRecursive(TreeNode root , int low , int high){
        if(root == null) return 0;
        int sum = 0;
        if(root.val >= low && root.val <= high) sum += root.val; 
        if(root.val > low) sum += rangeSumOfBST(root.left, low, high);
        if(root.val < high) sum += rangeSumOfBST(root.right, low, high);
        return sum;
    } 
}
