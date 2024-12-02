package HouseRobber;

public class Solution {
    public static void main(String[] args){
        int[] nums = {2,1,1,2};
        System.out.println(rob(nums));
    } 
    private static int rob(int[] nums){
        int n = nums.length;
        if(n < 2) return nums[0];
        int[] dp = new int[n];
        for(int i = 0 ; i < n ; i++){
            if(i == 0 || i == 1){
                dp[i] = Math.max(nums[0],nums[1]);
            }else{
                dp[i] = Math.max(nums[i] + dp[i-2],dp[i-1]);
            }
        } 
        printArr(dp);
        return Math.max(dp[n-1],dp[n-2]);
    }
    private static void printArr(int[] nums){
        for(int x : nums){
            System.out.print(x + " ");
        }
        System.out.println();
    }
}