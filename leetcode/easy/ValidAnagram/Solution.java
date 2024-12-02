package ValidAnagram;

public class Solution{
    public static void main(String[]args){
        System.out.println(isAnagram("ab","ab"));

    }
    public static boolean isAnagram(String s, String t){
        if(s.length() != t.length()) return false;
        int [] seen = new int[26];
        for(int i = 0 ; i < s.length() ; i++){
            int index = s.charAt(i) - 'a';
            seen[index] = seen[index]+1 ; 
        }
        for(int i = 0 ; i < t.length() ; i++){
            int index = t.charAt(i) - 'a';
            seen[index] = seen[index]-1;
        }
        for(int i: seen){
            if(i != 0){
                return false;
            }
        }
        return true;
    }

}