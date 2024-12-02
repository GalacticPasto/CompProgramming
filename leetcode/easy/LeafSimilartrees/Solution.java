package LeafSimilartrees;

import java.util.ArrayList;

public class Solution {
    public static void main(String[] args){
        

    } 

    private static boolean leafSimilar(TreeNode root1, TreeNode root2) {
        if(root1 == null && root2 != null){
            return false;
        }
        if(root1 == null && root2 == null){
            return true;
        }
        if(root1.val != root2.val){
            return false;
        }
        ArrayList<Integer> root1A = new ArrayList<>();
        ArrayList<Integer> root2B = new ArrayList<>();

        root1A = dfs(root1, root1A); 
        root2B = dfs(root2, root2B); 
        
        return root1A.equals(root2B); 
    }
    private static ArrayList<Integer> dfs(TreeNode root, ArrayList<Integer> list){
        if(root == null){
            return null;
        }
        if(root.left == null && root.right == null){
            list.add(root.val);
        }
        dfs(root.left, list);
        dfs(root.right, list);
        return list;
    }
    private static void printList(ArrayList<Integer> list){
        for(int i : list){
            System.out.print(i);
        }
        System.out.println();
    }
}
