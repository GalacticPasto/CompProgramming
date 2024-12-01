package RangeSumOfQuery;


public class Solution {
    public static void main(String[] args){
            int[] nums = {-2, 0, 3, -5, 2, -1};
            NumArray numArray = new NumArray(nums);
            System.out.println(numArray.sumRange(0, 2));
            System.out.println(numArray.sumRange(2, 5));
            System.out.println(numArray.sumRange(0, 5));
             // return (-2) + 0 + 3 = 1
             // return 3 + (-5) + 2 + (-1) = -1
             // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3

    }
    private static class NumArray {
        int[] array;
        int[] orig;
        private NumArray(int[] nums) {
            orig= nums; 
            array = new int[nums.length];
            array[0] = nums[0];
            for(int i = 1 ; i < nums.length ; i++){
                array[i] = nums[i] + array[i-1];
            }
            printArray(array);
        }

        private int sumRange(int left, int right) {
            if (left == 0) {
                return array[right];
            } else {
                return array[right]-array[left-1];
            }
        }
        private void printArray(int[] array){
            for(int i : array){
                System.out.print(i + ", ");
            }
            System.out.println();
        }
    }
}
