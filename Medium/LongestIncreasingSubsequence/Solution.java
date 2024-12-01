package LongestIncreasingSubsequence;

public class Solution {
    public static void main(String[] args){
        int[] nums = {0,1,0,3,2,3};
        System.out.println(lengthOfLIS(nums));
    } 
    private static int lengthOfLIS(int[] nums){
        int n = nums.length;
        int[] dp = new int[n];
        for(int i = 1 ; i < n ; i++){
            dp[i] = 1;
            for(int j = 0 ; j < i; j++){
                if(nums[i] > nums[j] && dp[i] < dp[j]+1){
                    dp[i] = dp[j] + 1;
                }
            }
        }
        printArr(dp);
        int max = 0;
        for(int i : dp){
            max = Math.max(i,max);
        }
        return max;
    }
    private static void printArr(int[] nums){
    for(int x : nums){
        System.out.print(x + " ");
    }
    System.out.println();
    }
}
