package LargestSubstringBetweenTwoEqualCharacters;

import java.util.HashMap;

public class Solution {
    public static void main(String[] args) {
        System.out.println(maxLengthBetweenEqualCharacters("abxxxxa"));
    }

    private static int maxLengthBetweenEqualCharacters(String s) {
        int max = 0;
        HashMap<Character,Integer> map = new HashMap<>();
        for(int i = 0 ; i < s.length() ;i++){
            map.put(s.charAt(i),i); 
        }
        if(map.size() == 1)return 0;
        for(int i = 0 ; i < s.length() ;i++){
            char c = s.charAt(i);
            if(i == map.get(c)) continue;
            int diff = map.get(c) - i-1;
            max = Math.max(diff,max);
        }
        return (max == 0) ? -1 : max;
    }

}
