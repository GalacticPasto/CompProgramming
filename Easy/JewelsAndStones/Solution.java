package JewelsAndStones;

import java.util.Hashtable;

public class Solution {
    public static void main(String [] args){
        System.out.println(numJewelsInStones("aA", "aAAbbbb"));

    } 
    private static int numJewelsInStones(String jewels, String stones){
        Hashtable<Character,Integer> table = new Hashtable<>();
        for(int i = 0 ; i < jewels.length(); i++){
            char c = jewels.charAt(i);
            table.put(c,0);
        }
        int sum = 0;
        for(int i = 0 ; i < stones.length(); i++){
            char c = stones.charAt(i);
            if(table.containsKey(c)){
                sum++;
                continue;
            }
        }
        return sum;
    }
    
}
