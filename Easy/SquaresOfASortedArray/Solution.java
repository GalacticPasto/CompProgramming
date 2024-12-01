package SquaresOfASortedArray;

public class Solution {
    public static void main(String []args){
        int[] nums = {-4,-1,0,3,10};
        printArray(sortedSquares(nums));

    } 
    private static int[] sortedSquares(int[] nums){
        int n = nums.length;
        int[] ans = new int[n];
        int i = 0 ;
        int j = n-1;
        for(int k = j ; k >= 0 ; k--){
            if(Math.abs(nums[i]) > Math.abs(nums[j])){
                ans[k] = nums[i] * nums[i];
                i++;
            }
            else{
                ans[k] = nums[j] * nums[j];
                j--;
            }
        }
        return ans;
    }
    private static void printArray(int[] nums){
        for(int i : nums){
            System.out.print(i + " ");
        }
        System.out.println();
    }
}
