package RemoveElement;


public class Solution {
    public static void main(String[] args){
        int[] nums ={3,2,2,3};
        System.out.println(removeElement(nums, 2));
    } 
    private static int removeElement(int[] nums, int val){
        int i = 0;
        int j = nums.length-1;
        int count = 0;
        while(i < j){
            if(nums[j]== val){
                j--;
                continue;
            }
            if(nums[i] == val){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp; 
                count++;
                j--;
            }
            i++;
        }
    printArray(nums);
    return i;
    }
    private static void printArray(int[] nums){
        for(int i : nums){
            System.out.print(i);
        }
        System.out.println();
    }
}

