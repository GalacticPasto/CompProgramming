package Base10ToBase7;

public class Solution {
    public static void main(String[] args){
        System.out.println(base10ToBase7(-7));
    } 
    private static String base10ToBase7(int n){
        int temp = n;
        boolean isNegative = false;
        if(temp < 0){
            isNegative = true; 
            temp *=-1;
        }
        StringBuilder sb = new StringBuilder();
        while(temp > 0){
            int remainder = temp%7; 
            sb.append(remainder);
            temp/=7;
        }
        if(isNegative){
            sb.append('-');
        }
        return sb.reverse().toString();
    }
}
