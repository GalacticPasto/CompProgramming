package BinaryTreePreorderTraversal;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Solution {
   public static void main(String[] args){

        TreeNode rightR = new TreeNode(7);
        TreeNode rightL = new TreeNode(6);
        TreeNode right = new TreeNode(3,rightL,rightR);
        TreeNode leftR = new TreeNode(5);
        TreeNode leftL = new TreeNode(4);
        TreeNode left = new TreeNode(2,leftL,leftR);
        TreeNode root = new TreeNode(1, left, right);
        printList(binaryTreePreorderTraversal(root));

   } 
   private static List<Integer> binaryTreePreorderTraversal(TreeNode root){
        if(root == null) {
            return null;
        }    
        List<Integer> ans = new ArrayList<>();
        bTPTItterative(root, ans);
        return ans;
   }
   private static void bTPT(TreeNode root, List<Integer>ans){
        if(root == null){
            return;
        }
        ans.add(root.val);
        bTPT(root.left, ans);
        bTPT(root.right, ans);
   }
   private static void bTPTItterative(TreeNode root, List<Integer> ans){
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        while(!stack.isEmpty()){
            TreeNode temp = stack.pop();
            if(temp == null){ continue;}
            ans.add(temp.val);
            stack.push(temp.right);
            stack.push(temp.left);
        }
   }
   private static void printList(List<Integer> ans){
        for(int i : ans){
            System.out.print(i);
        }
        System.out.println();

   }
}
