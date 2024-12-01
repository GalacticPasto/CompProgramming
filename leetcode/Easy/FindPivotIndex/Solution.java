package FindPivotIndex;

public class Solution {
    public static void main(String[] args){
        int[] ar = {-1,-1,0,1,1,0};
        int r = pivotIndex(ar);
        System.out.println(ar[r]);
    } 
    private static int pivotIndex(int[] nums){
        int leftSum = 0;
        int rightSum = 0;
        for(int i = 0 ; i < nums.length ; i++){
            rightSum +=nums[i];
        }
        if(nums[0] == rightSum)return 0;
        rightSum -= nums[0];
        for(int i = 1 ; i <= nums.length ;i++){
            leftSum += nums[i - 1];
            rightSum -= nums[i];
            if(leftSum == rightSum){
                return i;
            }
        }
        return -1;
    }
}

