package ConvertSortedArrayToBinaryTree;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    public static void main(String [] args){
        int[] nums = {-10,-3,0,5,9};
        TreeNode temp = sortedaArrayToBST(nums);
        bfs(temp);
    } 
    public static TreeNode sortedaArrayToBST(int[] nums){
        return insert(nums, 0, nums.length-1);
    }
    private static TreeNode insert(int[]nums, int l , int h ){
        while(l > h){
            return null;
        }
            int mid = l+(h-l)/2;
            TreeNode root = new TreeNode(nums[mid]);
            root.left = insert(nums, l, mid-1);
            root.right = insert(nums, mid+1, h);
        return root;
    }
    private static  void bfs(TreeNode root){
        Queue<TreeNode> q = new LinkedList<>(); 
        q.offer(root);
        while(!q.isEmpty()){
            TreeNode temp = q.poll();
            if(temp == null){
                continue;
            }
            System.out.print(temp.val + "--->");
            q.offer(temp.left);
            q.offer(temp.right);
        }
        System.out.println();
    }
     public static void inOrder(TreeNode root){
        if(root == null){
            return;
        }
        inOrder(root.left);
        System.out.print(root.val+ " ");
        inOrder(root.right);
    }
}
