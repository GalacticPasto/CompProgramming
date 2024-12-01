package BinaryTreePaths;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public static void main(String[]args){
        TreeNode right = new TreeNode(3);
        TreeNode leftLeftLeft = new TreeNode(7);
        TreeNode leftLeft = new TreeNode(6,leftLeftLeft,null);
        TreeNode leftRight = new TreeNode(5);
        TreeNode left = new TreeNode(2,leftLeft,leftRight);
        TreeNode root = new TreeNode(1, left, right);

        printList(binaryTreePaths(root));
    } 
    private static List<String> binaryTreePaths(TreeNode root){
        if(root == null){
            return null;
        }
        List<String> list = new ArrayList<>();
        dfs(root, "",list);
        return list;
    }
    private static void dfs(TreeNode root,String path,List<String> ans){
        if(root == null){
            return;
        }
        if(root.left ==  null && root.right == null){
            ans.add(path + root.val);
        }
        if(root.left !=null){
            dfs(root.left, path+root.val + "-->", ans);
        }
        if(root.right !=null){
            dfs(root.right, path+root.val+ "-->", ans);
        }
    }
    private static void printList(List<String> list){
        for(int i = 0 ; i<list.size(); i++){
            System.out.println(list.get(i));
        }
    }

}
