package BackspaceStringCompare;

import java.util.Stack;

public class Solution {
   public static void main(String[] args){
    System.out.println(backspaceCompareAnother("ab#c", "ad#c"));

   } 
   private static boolean backspaceCompare(String s, String t){
    Stack<Character> s1 = new Stack<>();
    Stack<Character> t1 = new Stack<>();
    for(int i = 0 ; i < s.length(); i++){
        if(s.charAt(i) != '#'){
            s1.push(s.charAt(i));
            continue;
        }
        s1.pop();
    }
    for(int j = 0 ; j < t.length(); j++){
        System.out.println(j);
        if(t.charAt(j) != '#'){
            t1.push(t.charAt(j));
            continue;
        }
        t1.pop();
    }
   return s1.equals(t1);
   }
   private static boolean backspaceCompareAnother(String s ,String t){
        return(helper(s).equals(helper(t)));
   }
   private static String helper(String s) {
       StringBuilder sb = new StringBuilder();
       for (int i = 0; i < s.length(); i++) {
           if (s.charAt(i) != '#') {
               sb.append(s.charAt(i));
           } else if (sb.length() > 0) {
               sb.deleteCharAt(i - 1);
           }
       }
       System.out.println(sb.toString());
       return sb.toString();
   }
}
