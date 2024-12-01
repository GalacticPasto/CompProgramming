package AverageOfLevelsBinaryTree;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution {
    public static void main(String[] args){
        

    } 
    private List<Double> averageOfLevelsBinaryTree(TreeNode root){
        List<Double> list = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty()){
            int size = q.size();
            int sum = 0;
            int count = 0;
            double average = 0;
            while(size > 0){
                size--;
                TreeNode temp = q.poll();
                sum += temp.val;
                count++;
                q.offer(temp.left);
                q.offer(temp.right);
            }
            average = sum/count;
            list.add(average);
        }
        return list;
    }
    
}
