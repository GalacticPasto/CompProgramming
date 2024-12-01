package SortArrayByParity;

public class Solution {
    public static void main(String[] args){
        int[] nums = {1,0,3}; 
        printArray(sortArrayByParity(nums));
    } 
    private static int[] sortArrayByParity(int[] nums){
        int[] ans = nums;
        int j = ans.length-1;
        int i =0 ;
        while(i < j){
            if ((ans[j] & 1) == 1) {
                j--;
                continue;
            }
            if ((nums[i] & 1) == 1) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j--;
            }
            i++;
        }
        return ans;
    }
    private static void printArray(int[] nums){
        for(int i : nums){
            System.out.print(i);
        }
        System.out.println();
    }
}


