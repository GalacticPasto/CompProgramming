package SearchInsertPosition;

public class Solution {
    public static void main(String []args){
        int [] nums = {1,3,5,6};
        System.out.println(searchInsert(nums, 0));    

    } 
    private static int searchInsert(int[]nums,int target){
        int n = nums.length;
        int low =0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(target > nums[mid]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
}
