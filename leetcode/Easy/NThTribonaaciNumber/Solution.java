package NThTribonaaciNumber;

public class Solution {
    static int[] fib;
    public static void main(String[] args){
        System.out.println(tribonnaci(4));
    }
    private static int tribonnaci(int n){
        fib = new int[n+1];
        fib[0] = 0;
        fib[1] = 1;
        fib[2] = 1;
        for(int i = 3 ; i < fib.length; i++){
            fib[i] = fib[i-1] + fib[i-2] + fib[i-3]; 
        }
        return fib[n-1] + fib[n-2] + fib[n-3];
    }
}
