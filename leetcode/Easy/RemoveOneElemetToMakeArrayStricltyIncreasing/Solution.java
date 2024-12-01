package RemoveOneElemetToMakeArrayStricltyIncreasing;

public class Solution{
    public static void main(String[] args){
        int[] nums = {105,924,32 ,968};
        int[] wrf = {1,2,10,11,5,7};
        System.out.println(canBeIncreasing(nums));
        System.out.println(canBeIncreasing(wrf));
    }
    private static boolean canBeIncreasing(int[] nums){
        boolean isIncreasing = false;
        int counter = 0;
        while(!isIncreasing && counter < nums.length){
            int[] ans = removeInd(nums, counter);
            isIncreasing = isIncreasing(ans);
            counter++;
        }
        printArray(nums);
        return isIncreasing;
    } 
    private static boolean isIncreasing(int[] arr){
        for(int i = 1; i < arr.length;i++){
            if(arr[i-1] >= arr[i])return false;
        }
        return true;
    }
    private static int[] removeInd(int[] nums, int ind){
        int[] ans = new int[nums.length-1]; 
        int counter = 0;
        for(int i = 0 ; i < nums.length; i++){
            if(i == ind) continue;
            ans[counter] = nums[i];
            counter++;
        }
        return ans;
    }
    private static void printArray(int[] arr){
        for(int i : arr){
            System.out.print(i + " ");
        }
        System.out.println();
    }
}