package CountBinarySubStrings;

public class Solution {
    public static void main(String[] args){
        System.out.println(countBinarySubStrings("00110011"));

    } 
    public static int countBinarySubStrings(String s){
        int prev = 0 ; 
        int current = 1 ; 
        int ans = 0;
        for(int i =1 ; i < s.length() ;i++){
            if(s.charAt(i) == s.charAt(i-1)){
                current++;
            }
            else{
                ans += Math.min(current,prev);
                prev = current;
                current = 1;
            }
        }
        return ans + Math.min(current,prev);
    }
}
