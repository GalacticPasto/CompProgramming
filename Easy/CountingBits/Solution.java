package CountingBits;

public class Solution {
    public static void main(String []args){
        printArray(countBitsNLogN(5));
        countBits(0);
        countBitsInternet(0);
    } 
    private static int[] countBits(int n){
        int[]ans = new int[n+1];
        for(int i = 0 ; i < ans.length ; i++){
            if((i & 1) ==1){
                ans[i] = 1 + (ans[i/2]);
            }
            else{
                int x = i/2;
                ans[i] = ans[x];
            }
        } 
        
        return ans;
    }

    private static int[] countBitsNLogN(int n) {
        int[] ans = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            int num = i;
            int count = 0;
            while (num > 0) {
                if ((num & 1) == 1){
                    count++;
                }
                num = num >> 1;
                ans[i] = count;
            }
        }
        return ans;
    }
    private static void printArray(int []nums){
       for(int i : nums){
            System.out.print(i + " ");
       } 
       System.out.println();
    }

    private static int[] countBitsInternet(int n) {
        int ans[] = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            int num = i, cnt = 0;
            while (num > 0) {
                if ((num & 1) == 1)
                    cnt++;
                num = num >> 1;
            }
            ans[i] = cnt;
        }
        return ans;
    }
}
