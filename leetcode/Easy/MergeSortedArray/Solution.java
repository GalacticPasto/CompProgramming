package MergeSortedArray;

public class Solution {
    public static void main(String[] args){
        int[] num1 = {0};
        int[] num2 = {1};
        merge(num1, 0, num2,1 );
        for(int i : num1){
            System.out.print(i);
        } 
    } 
    private static void merge(int[] nums1, int m , int[] nums2 , int n){
        int i = m-1;
        int k = n-1;
        int j = m+n-1;
        while(i >= 0 && k >= 0){
            if(nums1[i] < nums2[k]){
                nums1[j--] = nums2[k--];
            }
            else{
                nums1[j--] = nums1[i--];
            }
        }
        while(k >=0){
            nums1[j--] = nums2[k--];
        }
    }
}
