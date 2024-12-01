package SymmetricTree;

import java.util.LinkedList;
import java.util.Queue;

public class Solution{

        public static void main(String []args){
            TreeNode rightRight = new TreeNode(3);
            TreeNode right = new TreeNode(2,null,rightRight);
            TreeNode leftRight = new TreeNode(3);
            TreeNode left = new TreeNode(2,null,leftRight);
            TreeNode root = new TreeNode(1,left,right);
            
            System.out.println(isSymmetric(root));
        }
        public static boolean isSymmetric(TreeNode root){
            if(root == null){
                return false;
            }
            return helper(root.left, root.right);
        }
        public static boolean helper(TreeNode left , TreeNode right){
            if(left == null && right == null){
                return true;
            }
            if(left == null || right == null){
                return false;
            }
            if(left.val != right.val){
                return false;
            }
            return helper(left.left, right.right) && helper(left.right,right.left);
        }
        public static  void bfs(TreeNode root){
            Queue<TreeNode> q = new LinkedList<TreeNode>();
            q.add(root);
            while(!q.isEmpty()){
                TreeNode node = q.poll();
                System.out.print(node.val + "  ");
                if(node.left != null){
                    q.offer(node.left);
                }
                if(node.right !=null){
                    q.offer(node.right);
                }
            }
        }
    }