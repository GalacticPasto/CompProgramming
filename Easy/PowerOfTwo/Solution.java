package PowerOfTwo;

public class Solution {
    public static void main(String[] args){


    }
    private static boolean isPowerOfTwo(int n){
        if(n <= 0) return false;
        int setBits= 0; 
        int temp = n;
        while(temp > 0){
            temp = temp & (temp-1); 
            setBits++;
        }
        if(setBits == 1){
            return true;
        }
        else{
            return false;
        }
    }
}
