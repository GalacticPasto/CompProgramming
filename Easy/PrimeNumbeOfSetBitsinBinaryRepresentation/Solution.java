package PrimeNumbeOfSetBitsinBinaryRepresentation;

public class Solution {
    public static void main(String[] args){
        System.out.println(countPrimeBits(6,10));
    } 
    private static int countPrimeBits(int left, int right){
        int prime = 0;
        for(int i = left ; i <= right ; i++){
            int counter = 0;
            int temp = i;
            while(temp > 0){
                if((temp & 1)==1){
                    counter++;
                    System.out.println(i + ":" +counter);
                }
                temp = temp >> 1;
            }
            if(isPrime(counter)){
                prime++;
            }
        }
        return prime;
    }
    private static boolean isPrime(int n){
        if(n == 1){
            return false;
        }
        for(int i = 2; i < n ;i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
}
