package FindCommonCharacters;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    public static void main(String [] args){
        String[] words = {"bella","label","roller"};
        printArray(commonChars(words));
    } 
    private static List<String> commonChars(String[] words) {
        List<String> ans = new ArrayList<>();  
        int[] common = new int[26];
        Arrays.fill(common,Integer.MAX_VALUE);
        for(String w : words){
            int[] countArr = new int[26];
            for(char ch : w.toCharArray()){
                countArr[ch - 'a']++;
            }
            for(int i = 0 ; i < 26 ; i++){
                common[i] = Math.min(countArr[i],common[i]);
            }
        }
        for(int i = 0 ; i < 26 ; i ++){
            while(common[i] > 0){
                ans.add("" + (char)('a' + i));
                common[i]--;
            }
        }
        return ans;
    }
    private static void printArray(List<String> ans){
        for(String c : ans){
            System.out.print(c);
        }
        System.out.println();
    }
}
