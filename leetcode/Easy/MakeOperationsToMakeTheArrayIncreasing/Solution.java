package MakeOperationsToMakeTheArrayIncreasing;

public class Solution {
    public static void main(String[] args){
        int[] nums = {1,5,2,4,1};
        System.out.println(minOperations(nums));
    } 
    private static int minOperations(int[] nums){
        int ans = 0;
        for(int i = 1 ; i < nums.length; i++){
            if(nums[i] <= nums[i-1]){
                int difference = nums[i-1] - nums[i]+1;
                ans+= difference;
                nums[i]+= difference;
            }
        }
        return ans;
    }
}
