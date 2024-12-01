package MaximumAverageSubarrayI;

public class Solution {
    public static void main(String[] args){
        int[] nums = {1,12,-5,-6,50,3};
        System.out.println(findMaxAverage(nums, 4));
    } 
    private static double findMaxAverage(int[] nums , int k){
        double sum = 0.0;
        for(int i = 0 ; i < k; i++){
            sum+= nums[i]; 
        }
        double res = sum;
        for(int j = k ; j < nums.length ; j++){
            sum = sum - nums[j-k] + nums[j];
            res = Math.max(res,sum); 
        }
        return res/k;
    }
}
