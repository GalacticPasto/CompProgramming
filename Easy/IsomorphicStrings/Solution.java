package IsomorphicStrings;

import java.util.Hashtable;

public class Solution {
    public static void main(String[] args){
        System.out.println(isIsomorphic("foo", "bar"));

    } 
    private static boolean isIsomorphic(String s, String t){
        Hashtable<Character,Character> table = new Hashtable<>();
        int i = 0;
        int j =0;
        while(i < s.length() && j < t.length()){
            char c = s.charAt(i);
            char d = t.charAt(j);
            if(!table.containsKey(c)){
                if(!table.containsValue(d)){
                    table.put(c,d);
                }
                else{
                    return false;
                }
            }
            else{
                if(table.get(c) == d){
                    table.put(c,d);
                }
                else{
                    return false;
                }
            }
            i++;
            j++;
        }
        return true;
    }
}
