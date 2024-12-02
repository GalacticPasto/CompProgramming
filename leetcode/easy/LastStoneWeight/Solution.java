package LastStoneWeight;

import java.util.Collections;
import java.util.PriorityQueue;

public class Solution {
    public static void main(String[] args){
        int[] stones = {2,7,4,1,8,1};
        System.out.println(lastStoneWeight(stones));
    } 
    private static int lastStoneWeight(int[] stones){
        PriorityQueue<Integer> queue = new PriorityQueue<>(Collections.reverseOrder());        
        for(int i : stones){
            queue.offer(i);
        }
        while(queue.size() >= 2){
            int a = queue.poll();
            int b = queue.poll();
            int ans = a - b ;
            queue.offer(ans);
        }
        return queue.poll();
    }
}
