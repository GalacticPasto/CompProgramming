package MergeTwoBInaryTrees;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {
   public static void main(String []args){
        TreeNode root1Right = new TreeNode(2);
        TreeNode root1LeftLeft = new TreeNode(5);
        TreeNode root1Left = new TreeNode(3,root1LeftLeft,null);
        TreeNode root1 = new TreeNode(1,root1Left,root1Right);


        TreeNode root2RightRight = new TreeNode(7);
        TreeNode root2Right = new TreeNode(3,null,root2RightRight);
        TreeNode root2LeftRight= new TreeNode(4);
        TreeNode root2Left = new TreeNode(1,null,root2LeftRight);
        TreeNode root2 = new TreeNode(2,root2Left,root2Right);

        printTree(root1);
        printTree(root2);
        printTree(mergeTreesRecursive(root1, root2));
   } 
   private static TreeNode mergeTreesRecursive(TreeNode root1, TreeNode root2){
        if(root1 == null && root2 == null) return null;
        if(root1 ==null)return root2;
        if(root2 ==null)return root1;
        TreeNode node = new TreeNode(root1.val + root2.val);
        node.left = mergeTreesRecursive(root1.left, root2.left);
        node.right = mergeTreesRecursive(root1.right, root2.right);
        return node;
   }

   private static void printTree(TreeNode root) {
       Queue<TreeNode> q = new LinkedList<>();
       q.offer(root);
       while (!q.isEmpty()) {
           TreeNode temp = q.poll(); 
            if(temp==null){
                continue;
            } 
           System.out.print(temp.val + " ");
           q.offer(temp.left);
           q.offer(temp.right);
       }
       System.out.println();
   }
}
