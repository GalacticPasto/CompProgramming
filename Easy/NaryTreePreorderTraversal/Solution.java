package NaryTreePreorderTraversal;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Solution {
    private static ArrayList<Integer> list;
    public static void main(String[] args){

    } 
    private static List<Integer> preorder(Node root){
        list = new ArrayList<>();
        dfs(root, list);
        return list;
    }
    private static void dfs(Node root, ArrayList<Integer> list){
        if(root == null){
            return;
        }
        list.add(root.val);
        for(int i = 0; i < root.children.size(); i++){
            dfs(root.children.get(i), list);
        }
    }
}
