package AddDIgits;

public class Solution {
    public static void main(String[] args){
        System.out.println(addDigits(7));
         
    } 
    private static int addDigits(int num){
        int sum = 0;
        int temp = num;

        int digit = temp % 10;
        temp /= 10;
        sum += digit + temp; 

        if(sum <= 10) return sum;

        return addDigits(sum);
    }
    private static int getSum(int num) {
        int temp = num;
        int digit = 0;
        int sum = 0;
        while(temp > 10){
            digit = temp % 10;
            temp /= 10;
            if(temp < 10){
                sum += digit + temp;
            }
            else{
                sum += digit;
            }
        }
        return sum;
    }
    private static int addDigitsConstantTime(int num){
        if(num ==0){
            return 0;
        }
        return (num % 9 == 0) ? 9 : (num % 9);
    }
}
