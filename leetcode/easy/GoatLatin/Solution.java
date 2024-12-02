package GoatLatin;

import java.util.HashSet;

public class Solution {
    public static void main(String[] args){
        System.out.println(toGoatLatin("I speak Goat Latin"));
    } 
    private static String toGoatLatin(String sentence){
        String[] words = sentence.split(" "); 
        HashSet<Character> vowels = new HashSet<>();
        
        vowels.add('a');
        vowels.add('e');
        vowels.add('i');
        vowels.add('o');
        vowels.add('u');

        StringBuilder ans = new StringBuilder();
        for(int j = 0 ; j < words.length ; j++){

            char c = words[j].toLowerCase().charAt(0);

            if(vowels.contains(c)){
                for(int i = 0 ; i < words[j].length() ;i++){
                    ans.append(words[j].charAt(i));
                }
                ans.append("ma");
                int temp = j+1;
                while(temp > 0){
                    ans.append("a");
                    temp--; 
                }
            }
            else{
                for(int i = 1 ; i < words[j].length() ;i++){
                    ans.append(words[j].charAt(i));
                }

                ans.append(words[j].charAt(0));
                ans.append("ma");

                int temp = j+1;
                while(temp > 0){
                    ans.append("a"); 
                    temp--;
                }
            }
            ans.append(" ");
        }
        return ans.deleteCharAt(ans.length()-1).toString();
    }
}
