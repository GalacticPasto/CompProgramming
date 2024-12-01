package PlusOne;

public class Solution {
    public static void main(String[] args){
        int[] ar={1,3,4,5,6,9,9}; 
        printArray(plusOne(ar));
    } 
    private static int[] plusOne(int[] digits){
        int n = digits.length;
        for(int i = n-1; i>= 0; i--){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        int[]ans = new int[n+1];
        ans[0] = 1;
        return ans;
    }
    private static void printArray(int[] array){
        for(int i: array){
            System.out.print(i);
        }
        System.out.println();
    }
}
