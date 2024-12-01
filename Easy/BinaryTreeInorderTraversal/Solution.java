package BinaryTreeInorderTraversal;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Solution {
    public static void main(String []args){
        TreeNode right = new TreeNode(3);
        TreeNode leftRight = new TreeNode(5);
        TreeNode leftLeft = new TreeNode(4);
        TreeNode left = new TreeNode(2,leftLeft,leftRight);
        TreeNode root = new TreeNode(1,left,right);
        printList(binaryTreeInorderTraversalItterative(root));
    } 

    private static List<Integer> binaryTreeInorderTraversalItterative(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode temp = root;
        while (!stack.isEmpty() || temp != null) {
            if(temp != null){
                stack.push(temp);
                temp = temp.left;
            } 
            else{
                temp = stack.pop();
                list.add(temp.val);
                temp = temp.right;
            }
        }
        return list;
    }
    // private static List<Integer> binaryTreeInorderTraversalRecusrion(TreeNode root){

    // }
    // private static void dfs(TreeNode root , List<Integer> result){
        
    // }
    private static void printList(List<Integer> result){
        for(int i : result){
            System.out.print(i + " ");
        }
        System.out.println();
    }
}
