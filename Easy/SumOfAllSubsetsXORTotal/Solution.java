package SumOfAllSubsetsXORTotal;

public class Solution {
    public static void main(String[] args){
        int[] arr = {3,4,5,6,7,8}; 
        System.out.println(subsetXORSum(arr));
        
    }
    private static int subsetXORSum(int[] nums){
        int sum = 0 ;
        for(int i = 0; i < nums.length ; i++){
            sum += nums[i];
        }
        for(int i = 0 ; i < nums.length; i++){
            calculateSubsetXOr(nums,i,nums.length-i-1,sum); 
        }
        return sum; 
    }
    private static void calculateSubsetXOr(int[] nums, int start,int end, int sum){
        int xor = 0;
        int counter = 0;
        while(counter < end){
            for(int i = end - counter ; i >= start; i--){
                xor ^= nums[i];  
                System.out.print(nums[i] + " " );
            }
            System.out.println();
            counter++;
        }
        sum+= xor;
    }
}
