package PalindromeNumber;

public class Solution {
    public static void main(String[]args){
        System.out.println(isPalidrome(10));

    } 
    public static boolean isPalidrome(int x){
        int n =0;
        int temp = x;
        while(temp !=0){
            int digit = temp%10;
            n = n*10 + digit;
            temp = temp/10;
        }
       return (n==x); 
    }
}
