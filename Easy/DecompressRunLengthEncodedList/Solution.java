package DecompressRunLengthEncodedList;
public class Solution{

    public static void main(String[] args){
       int[] nums = {65,44,72,15};
       printArr(decompressRLElist(nums)); 
    }
    private static int[] decompressRLElist(int[] nums){
        int n = nums.length;
        int length = 0;
        for(int i = 0 ; i < nums.length ;i+=2){
            length += nums[i];    
        }

        int j = 0;
        int[] ans = new int[length];      

        for (int i = 0; i < n; i += 2) {
            int freq = nums[i];
            int val = nums[i + 1];
            
            while(freq > 0 && j < ans.length){
                ans[j++] = val;
                freq--;
            }
        }
        return ans;
    }
    private static void printArr(int[] arr){
        for(int i : arr){
            System.out.print(i + " ");
        }
        System.out.println();
    }
}   


