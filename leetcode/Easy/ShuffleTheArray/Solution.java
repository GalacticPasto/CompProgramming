package ShuffleTheArray;

public class Solution {
    public static void main(String[] args){
        int[] nums = {2,5,1,3,4,7};
        printArr(shufffle(nums, 3));
    } 
    private static int[] shufffle(int[] nums, int n){
        int[] ans = new int[nums.length];
        int i = 0;
        int j = n;
        int k = 0;
        while(i <= n && j < nums.length){
            ans[k] = nums[i];
            k++;
            ans[k] = nums[j]; 
            i++;
            j++;
            k++;
        }
        return ans;
    } 
    private static void printArr(int[] nums){
        for(int i : nums){
            System.out.print(i + ",");
        }
        System.out.println();
    }
}
