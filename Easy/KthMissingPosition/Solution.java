package KthMissingPosition;

public class Solution {
    public static void main(String[] args) {
        int[] nums = {1,2};
        System.out.println(kthMissingNumberBinarySearch(nums, 1));
        kthMissingNumber(nums, 0);
    }
    private static int kthMissingNumber(int[] arr, int k){
        int temp = k;
        for(int i = 0 ; i < arr.length ;i++){
            if(arr[i] <= temp){
                temp++;
                System.out.println(temp);
            }
        }
        return temp;
    }
    private static int kthMissingNumberBinarySearch(int[] arr, int k){
        int low = 0 ; 
        int high = arr.length-1; 
        while(low <= high){
            int mid = low +(high - low)/2;
            int missing = arr[mid] - mid +1;
            if(missing <= k){
                low = mid +1;
            }
            else{
                high = mid-1;
            }
        }
        return low + k;

    }
}
