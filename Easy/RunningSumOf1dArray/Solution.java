package RunningSumOf1dArray;

public class Solution {
    public static void main(String[] args){
        int[] nums = {1,2,3,4};
        printArray(runningSum(nums));
    }  
    private static int[] runningSum(int[] nums){
        int[] ans = nums;
        for(int i = 1; i < nums.length ; i++){
            ans[i] = ans[i-1] + ans[i];
        }
        return ans;
    }
    private static void printArray(int[] nums){
        for(int i : nums){
            System.out.print(i);
        }

    }
}
