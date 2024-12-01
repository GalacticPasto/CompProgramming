package TwoSum;

import java.util.HashMap;

public class Solution {
    public int[] bruteForceSolution(int[] nums, int target) {
        for (int i = 1; i < nums.length; i++) {
            for(int j = i ; j < nums.length ; j++){
                if(target== nums[j-i] + nums[j]){
                    return new int[]{j-i,j};
                }
            }
        }
        return new int[] {};
    }

    public int[] hashMapSolution(int[] nums , int target){
        HashMap<Integer, Integer> heap= new HashMap<Integer, Integer>();
        for(int i = 0 ; i < nums.length; i++){
            int diffrence = target-nums[i];
            if(heap.containsKey((Integer)diffrence)){
                return new int[]{(int)heap.get(diffrence), i};
            }
            heap.put(nums[i],i);
        }
        return new int[]{};
    }
    protected void printArray(int[] nums){
        for(int i = 0 ; i < nums.length; i++){
            System.out.print(nums[i] + " ");
        }
        System.out.println();
    }
}
