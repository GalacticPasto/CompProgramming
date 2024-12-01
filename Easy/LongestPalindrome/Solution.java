package LongestPalindrome;

import java.util.HashSet;

public class Solution {
    public static void main(String[] args){
        System.out.println(longestPalindrome("abccccdd"));

    }

    private static int longestPalindrome(String s) {
        HashSet<Character> set = new HashSet<>();
        int count = 0 ;
        for(int i = 0 ; i < s.length() ; i++){
            if(set.remove(s.charAt(i))){
                count++;
            }
            else{
                set.add(s.charAt(i));
            }
        }
        return set.isEmpty() ?  count * 2 : count * 2 +1;
    }
}
