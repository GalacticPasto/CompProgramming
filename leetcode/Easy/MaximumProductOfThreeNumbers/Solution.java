package MaximumProductOfThreeNumbers;

public class Solution {
    public static void main(String[] args){
        int[] nums = {-100,-98,0,1,2,3,4};
        System.out.println(maximumProductOfThreeNumbers(nums));
    } 
    private static int maximumProductOfThreeNumbers(int[] nums){
        int[] temp = new int[nums.length];
        int isNegative =0;
        for(int i = 0 ; i < nums.length ; i++){
            if(nums[i] < 0){
                isNegative++;
            }
            temp[i] = Math.abs(nums[i]);
        }
        partition(temp, 0,temp.length-1);
        int i = temp.length-1;
        int ans = temp[i-2] * temp[i-1] * temp[i];
        if((isNegative & 1) == 1){
            ans *=-1;
        }
        return ans;
    }
    private static int partition(int[] nums, int low , int high){
        int pivot = nums[high];
        int i = low; 
        int j = low;
        while(i <= high){
            if(nums[i] <= pivot){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j++;
            }
            i++;
        }
        return j-1;
    }
}
