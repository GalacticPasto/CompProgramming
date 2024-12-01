package SameTree;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    public static void main(String[] args) {
        TreeNode pRight = new TreeNode(3);
        TreeNode pLeft = new TreeNode(2);
        TreeNode p = new TreeNode(1,pLeft,pRight);

        TreeNode qRight = new TreeNode(3);
        TreeNode qLeft = new TreeNode(2);
        TreeNode q = new TreeNode(1,qLeft,qRight);
        System.out.println(isSameTree(p, q));
    }
    public static boolean isSameTree(TreeNode p , TreeNode q){
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(p);
        queue.offer(q);
        while(!queue.isEmpty()){
            TreeNode p1 = queue.poll();
            TreeNode q1 = queue.poll();
            if(p1 == null && q1 == null){
                continue;
            }
            if(p1 == null || q1 ==null || p1.val != q1.val){
               return false; 
            }
                queue.offer(p1.left);
                queue.offer(q1.left);
                queue.offer(p1.right);
                queue.offer(q1.right);
        }
        return queue.isEmpty();
    }
}
