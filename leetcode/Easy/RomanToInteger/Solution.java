package RomanToInteger;

import java.util.Hashtable;

public class Solution {
    public static void main(String[] args){
        System.out.println(romanToInteger("CDLXIV"));

    } 
    private static int romanToInteger(String s){
        Hashtable<Character,Integer> table = new Hashtable<>();
        table.put('I', 1);
        table.put('V', 5);
        table.put('X', 10);
        table.put('L', 50);
        table.put('C', 100);
        table.put('D', 500);
        table.put('M', 1000);
        int sum = 0;
        int n = s.length();
        for(int i = 0 ; i < n ; i++){
            if(i < n -1 && table.get(s.charAt(i)) < table.get(s.charAt(i+1))){
                sum -= table.get(s.charAt(i));
            }
            else{
                sum += table.get(s.charAt(i));
            }
        }
        return sum;
    }
}
