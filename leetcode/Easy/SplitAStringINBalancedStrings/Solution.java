package SplitAStringINBalancedStrings;

public class Solution {
    public static void main(String[] args){
        System.out.println(balancedStringSplit("RLRRRLLRLL"));
    } 
    private static int balancedStringSplit(String s){
        int noR = 0;
        int noL = 0;
        int count = 0;
        for(char c : s.toCharArray()){
            if(c == 'L'){
                noL++;
            }
            else{
                noR++;
            }
            if(noR == noL){
                count++;
                noL  = 0;
                noR = 0; 
            }
        }
        return count;
    }
}
