package MaxConsecutiveOnes;

public class Solution {
    public static void main(String [] args){
        int []nums = {1,1,0,1,1,1};
        System.out.println(findMaxConsecutiveOnes(nums));
    }
    private static int findMaxConsecutiveOnes(int[] nums){
        int maxSoFar = 0 ;
        int curr = 0;
        for(int i = 0 ; i < nums.length ; i++){
            if(nums[i] == 1){
                curr++;
            }
            else{
                maxSoFar = Math.max(maxSoFar,curr);
                curr = 0;
            }
        }
        return Math.max(maxSoFar, curr);
    }
}
