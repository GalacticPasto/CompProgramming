package SetMismatch;

import java.util.HashMap;

public class Solution {
    public static void main(String[] args){
        int[] nums = {2,2,3,4};
        printArr(findErrorNums(nums));
    } 
    private static int[] findErrorNums(int[] nums){
        HashMap<Integer,Integer> map = new HashMap<>();
        int missing = 0;
        int dup = 0;
        for(int i = 0 ; i < nums.length; i++){
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
        }
        for (int i = 1; i <= nums.length; i++) {
            if (map.containsKey(i)) {
                if (map.get(i) == 2) {
                    dup = i;
                }
            }
            else{
                missing = i;
            }
        }
        return new int[]{dup, missing};
    }
    private static void printArr(int[] arr){
        for(int i : arr){
            System.out.print(i + " ");
        }
        System.out.println();
    }
}

