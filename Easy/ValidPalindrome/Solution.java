package ValidPalindrome;

public class Solution {
    public static void main(String []args){
        isPalindrome(null);
    } 
    private static boolean isPalindrome(String s){
        int left = 0;
        int right = s.length()-1;
        while(left < right){
            char l = s.charAt(left);
            char r = s.charAt(right);
            if(!Character.isLetterOrDigit(l)){
                left++;
            }
            else if(!Character.isLetterOrDigit(r)){
               right--; 
            }
            if(Character.toLowerCase(l) != Character.toLowerCase(r)){return false;}
            left++;
            right--;
        }
        return true;
    }
}
