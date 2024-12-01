package BinaryTreePostOrderTraversal;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Solution {
    public static void main(String []args){
        TreeNode rightLeft = new TreeNode(3);
        TreeNode right = new TreeNode(2,rightLeft,null);
        TreeNode left = new TreeNode(0);
        TreeNode root = new TreeNode(1,left,right);
        printList(binaryTreePostOrderTraversalItterative(root));
    } 

    private static List<Integer> binaryTreePostOrderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        bstPostOrderTraversalRecursion(root, ans); 
        return ans;
    }
    private static void bstPostOrderTraversalRecursion(TreeNode root, List<Integer> output){
        if(root == null){
            return;
        }
        bstPostOrderTraversalRecursion(root.left, output);
        bstPostOrderTraversalRecursion(root.right, output);
        output.add(root.val);
    }
    private static void printList(List<Integer> ans){
        for(int i : ans){
            System.out.print(i + " ");
        }
    }
    private static List<Integer> binaryTreePostOrderTraversalItterative(TreeNode root){
        List<Integer> ans = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode current = root;
        while(!stack.isEmpty() || current != null){
            if(current != null){
                stack.push(current);
                current = current.left;
            }
            else{
                TreeNode temp = stack.peek().right;
                if(temp == null){
                    temp = stack.pop();
                    ans.add(temp.val);
                    while(!stack.isEmpty() && temp == stack.peek().right){
                        temp = stack.pop();
                        ans.add(temp.val);
                    }
                }
                else{
                    current = temp;
                }
            }
        }
        return ans;
    }
    
}
