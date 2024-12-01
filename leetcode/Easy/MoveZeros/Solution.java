package MoveZeros;

public class Solution {
    public static void main(String [] args){
        int[]nums = {1,0,1};
        printArray(nums);
        moveZeros(nums);
        printArray(nums);
    } 
    private static void moveZeros(int[] nums){
        int j = 0; 
        for(int i = 1 ; i < nums.length; i++){
            if(nums[i] == 0 && nums[j] != 0){
                j = i;
            }
            if(nums[i] != 0 && nums[j] == 0){
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                j++;
            }
        }
    }
    private static void printArray(int[]array){
        for(int i : array){
            System.out.print(i + " ");
        }
        System.out.println();
    }
}
