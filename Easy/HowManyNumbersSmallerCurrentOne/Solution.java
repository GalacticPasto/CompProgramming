package HowManyNumbersSmallerCurrentOne;

public class Solution {
    public static void main(String[] args){
        int[] nums = {8,1,2,2,3};
        printArray(smallerNumbersThanCurrentOne(nums));
    } 
    private static int[] smallerNumbersThanCurrentOne(int[] nums){
        int[] bucket = new int[100];
        for(int i : nums){
            bucket[i]++;
        }
        for(int i = 1; i < bucket.length ; i++){
            bucket[i] += bucket[i-1];
        }
        int[] result = new int[nums.length];
        for(int i = 0 ; i < nums.length ; i++){
            result[i] = bucket[nums[i]-1];
        }
        return result;
    }
    private static void printArray(int[] nums){
        for(int i : nums){
            System.out.print(i + " ");
        }
        System.out.println();
    }
} 