package VerifyingAlienDictonary;

import java.util.Hashtable;

public class Solution{
    public static void main(String[] args){
        String[] words = {"hello","leetcode"};
        System.out.println(isAlienSorted(words,"hlabcdefgijkmnopqrstuvwxyz"));
    }
    private static boolean isAlienSorted(String[] words, String order){
        Hashtable<Character,Integer> table = new Hashtable<>();        
        for(int i = 0 ; i < order.length() ; i++){
            char c = order.charAt(i);
            table.put(c,i+1);
        }
        for(int i = 1 ; i < words.length ; i++){
            if(!compare(words[i-1], words[i], table)){
                return false;
            }
        }
        return true;
    }
    private static boolean compare(String s, String r, Hashtable<Character,Integer> table){
        if(r.length() < s.length()){
            return false;
        } 
        for (int i = 0, j = 0; i < s.length() && j < r.length(); i++, j++) {
            char c = s.charAt(i);
            char d = r.charAt(j);
            if(c != d){
                if(table.get(c) > table.get(d)){
                    return false;
                }
                else{
                    return true;
                }
            }
        }
        return true;
    }
}