package LongestPalindromicSubstring;

public class Solution {
    public static void main(String[] args){
        String jaja = "aaabbaa";
        System.out.println(longestPalindromicSubstring(jaja));
    } 
    private static String longestPalindromicSubstring(String s){
        int n = s.length();
        int[][] dp = new int[n][n];
        String ans = "";
        for (int len = 1; len < n; len++) {
            for (int i = 0; i < n - len; i++) {
                int j = i + len;
                if (s.charAt(i) == s.charAt(j)) {
                    if (len == 1 || len == 2 || dp[i+1][j-1] == 1) {
                        dp[i][j] = 1; 
                        if(len > ans.length())ans = s.substring(i, j+1);   
                    }
                }
            }
        }
        return ans;
    }
}
