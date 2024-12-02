package DetermineIfStringHalvesAreALike;

import java.util.HashSet;

public class Solution {
    public static void main(String[] args){
        System.out.println(halvesAreALike("book"));
    } 
    private static boolean halvesAreALike(String s){
        int middle = s.length()/2;
        HashSet<Character> set = new HashSet<>();
        set.add('a');
        set.add('e');
        set.add('i');
        set.add('o');
        set.add('u');
        set.add('A');
        set.add('E');
        set.add('I');
        set.add('O');
        set.add('U');
        
        int left = 0;
        for(int i = 0 ; i < middle; i++){
            if(set.contains(s.charAt(i))){
                left++;
            } 
        }
        int right = 0;
        for(int i = middle ; i < s.length() ;i++){
            if(set.contains(s.charAt(i))){
                right++;
            }
        }
        return (left == right);
    }
}
