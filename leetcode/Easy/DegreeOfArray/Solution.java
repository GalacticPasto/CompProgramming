package DegreeOfArray;

import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class Solution {
    public static void main(String[] args) {
        int[] nums = {1};
        System.out.println(findShortestSubArray(nums));
    }
    private static int findShortestSubArray(int[] nums){
        HashMap<Integer, Integer> map = new HashMap<>(); 
        Map<Integer,Integer> left = new HashMap<>();
        Map<Integer, Integer> right = new HashMap<>();
        int maxDegree=0;
        for(int i = 0 ; i < nums.length ;i++){
            int num = nums[i];
            if(!map.containsKey(num)){
                map.put(num, 0);
                left.put(num,i);
            }
                map.put(num, map.get(num)+1);
                right.put(num, i);
        }
        maxDegree = Collections.max(map.values());
        int result = nums.length; 
        for(int i : map.keySet()){
            int leftInd= 0;
            int rightInd = 0;
            if(map.get(i) == maxDegree){
                leftInd = left.get(i);
                rightInd = right.get(i);
                result = Math.min(result, rightInd - leftInd + 1);
            }
        }
        return result;
    }
}
