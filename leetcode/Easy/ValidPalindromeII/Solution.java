package ValidPalindromeII;


public class Solution {
    public static void main(String []args){
        System.out.println(validPalindromeII("cat"));
    } 
    private static boolean validPalindromeII(String s){
        int i = 0;
        int j = s.length()-1;
        while(i <= j){
            if(s.charAt(i) == s.charAt(j)){
                i++;
                j--;
            }
            else{
                return isPalII(s, i+1, j) || isPalII(s, i, j-1);
            }
        }
        return true;
    } 
    private static boolean isPalII(String s, int i , int j){

        while(i <= j){
            if(s.charAt(i) == s.charAt(j)){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    } 
}
