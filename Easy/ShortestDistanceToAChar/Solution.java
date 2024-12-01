package ShortestDistanceToAChar;
public class Solution{
    public static void main(String[] args){
        printArray(shortestDistanceToAChar("aabaa", 'b'));
    }
    private static int[] shortestDistanceToAChar(String s , char c){
        int n = s.length();
        int[] ans = new int[n];
        int k = -n;
        for(int i = 0 ; i < n ; i++){
            if(s.charAt(i) == c){
                k = i;
            }
            ans[i] = i-k;
        }
        for(int i = n-1 ; i >= 0 ; i--){
            if(s.charAt(i) == c){
                k = i;
            }
            ans[i] = Math.min(ans[i], Math.abs(k-i));
        }
        return ans;
    }
    private static void printArray(int[] nums){
        for(int i : nums){
            System.out.print(i + ",");
        }
        System.out.println();
    } 
}
    
