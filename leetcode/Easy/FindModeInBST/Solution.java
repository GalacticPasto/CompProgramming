package FindModeInBST;

import java.util.Arrays;
import java.util.HashMap;

public class Solution{
    static int maxCount = 1;
    public static void main(String[] args){
        

    }
    private static int[] findMode(TreeNode root){
        HashMap<Integer,Integer> map = new HashMap<>();
        dfs(root, map);
        int[] ans = new int[map.size()];
        int j = 0 ;
        for(Integer i : map.keySet()){
            if(map.get(i) == maxCount){
                ans[j++] = i;
            }
        }
        return Arrays.copyOf(ans, j); 
    }
    private static void dfs(TreeNode root, HashMap<Integer,Integer> map){
        if(root == null){
            return;
        } 
        if(map.containsKey(root.val)){
            map.put(root.val,map.get(root.val) +1 );
            maxCount = Math.max(maxCount, map.get(root.val));
        }
        else{
            map.put(root.val, 1);
        }
        dfs(root.left, map);
        dfs(root.right, map);
    } 
}