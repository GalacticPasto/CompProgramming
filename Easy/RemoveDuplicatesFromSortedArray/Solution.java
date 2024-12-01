package RemoveDuplicatesFromSortedArray;

public class Solution {
    public static void main(String []args){
        int[] nums = {0,0,1,1,1,2,2,3,3,4};
        System.out.println(removeDuplicatesFromSortedArray(nums));
    } 
    private static int removeDuplicatesFromSortedArray(int[] nums){
        int element = nums[0];
        int count = 0; 
        for(int i = 1 ; i < nums.length ; i++){
            if(nums[i] == element){
                continue; 
            }
            else{
                element = nums[i];
                count++;
                nums[count] = element;
            }
        }
    printArray(nums);
    return count+1;
    }

    private static void printArray(int[] nums){
        for(int i: nums){
            System.out.print(i + " ");
        }
        System.out.println();
    } 
}
