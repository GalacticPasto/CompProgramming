package HappyNumber;

import java.util.HashSet;
import java.util.Set;
public class Solution {
    public static void main(String []args){
        System.out.println(isHappy(17));
    }

    public static boolean isHappy(int n) {
        Set<Integer> seen = new HashSet<>();
        while(true){
            seen.add(n);

            int sum = 0;
            while(n != 0){
            int digit = n%10;
            sum = sum+ digit*digit;
            n = n/10;
            }
            if(sum == 1){
                return true;
            }
            if(seen.contains(sum)){
                return false;
            }
            seen.add(sum);
            n = sum;
        }
    }
}
