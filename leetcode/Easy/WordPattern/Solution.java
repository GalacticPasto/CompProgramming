package WordPattern;

import java.util.Hashtable;

public class Solution {
    public static void main(String[] args){
        System.out.println(wordPattern("abba", "dog dog dog dog"));
    } 
    private static boolean wordPattern(String pattern, String s){
        Hashtable<Character, String > table = new Hashtable<>();
        String[] words = s.split(" ");
        for(int i = 0 ; i < pattern.length(); i++){
            char c = pattern.charAt(i);
            if(table.containsKey(c) && words[i].equals(table.get(c))){
                continue;
            }
            else{
                if(!table.containsKey(c) && !table.containsValue(words[i])){
                    table.put(c, words[i]);
                    System.out.println(words[i]);
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
}
