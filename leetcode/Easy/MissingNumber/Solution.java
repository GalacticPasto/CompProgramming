package MissingNumber;

public class Solution {
   public static void main(String []args){
    int[] nums = {9,6,4,2,3,5,7,0,1};
    System.out.println(missingNumber(nums));

   } 
   public static int missingNumber(int[] nums){
        int sum = 0;
        int n = nums.length;
        int naturalSum = 0;
        for(int i = 0 ; i < n; i++){
            sum = sum+nums[i];
            naturalSum = naturalSum+i+1;
        } 
    return Math.abs(naturalSum-sum);
   }
}
