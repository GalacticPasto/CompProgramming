package TwoSumIV;

import java.util.HashSet;
import java.util.Hashtable;
import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    public static void main(String[] args){
        TreeNode rightR = new TreeNode(7); 
        TreeNode right = new TreeNode(6,null,rightR); 
        TreeNode leftR = new TreeNode(4);
        TreeNode leftL = new TreeNode(2);
        TreeNode left = new TreeNode(3,leftL,leftR);
        TreeNode root = new TreeNode(5,left,right);
        System.out.println(findTargetRecursive(root, 9));
        findTarget(root, 0);
    }
    private static boolean findTarget(TreeNode root , int k){
        Queue<TreeNode> q = new LinkedList<>();
        Hashtable<Integer,Integer> table = new Hashtable<>();
        q.offer(root);
        while(!q.isEmpty()){
            TreeNode temp = q.poll(); 
            if(temp == null) continue;
            int difference = k - temp.val;
            if(table.containsKey(temp.val)){
                return true;
            }
            table.put(difference,temp.val);
            q.offer(temp.left);
            q.offer(temp.right);
        }
        return false;
    }
    private static boolean findTargetRecursive(TreeNode root , int k ){
        HashSet<Integer> set = new HashSet<>();
        return helperRecursion(set, root, k);
    }
    private static boolean helperRecursion(HashSet<Integer> set,TreeNode root, int k){
        if(root == null){
            return false;
        }    
        if(set.contains(k-root.val)){
            return true;
        }
        set.add(root.val);
        return helperRecursion(set, root.left, k) || helperRecursion(set, root.right, k);
    }
}
