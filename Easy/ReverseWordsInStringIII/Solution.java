package ReverseWordsInStringIII;

public class Solution {
    public static void main(String[] args){
        System.out.println(reverseWords("Let's take LeetCode contest"));

    } 
    private static String reverseWords(String s){
        String[] words = s.split(" ");
        StringBuilder sb = new StringBuilder();
        for(int i = 0 ; i < words.length ; i++){
            String temp = words[i];
            int pointer = temp.length()-1;
            while(pointer >= 0){
                sb.append(temp.charAt(pointer));
                pointer--;
            }
            sb.append(" ");
        }
        return sb.deleteCharAt(sb.length()-1).toString();
    }
}
