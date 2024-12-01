package CalculateMoneyInLeetcodeBank;

public class Solution {
    public static void main(String[] args){
        System.out.println(totalMoney(10));
    } 
    private static int totalMoney(int n){
        int ans = 0;
        int week = 0;
        while(n > 7){
            ans += 28 + (7 * week);
            week++;
            n -= 7;
        }
        for(int i = week+1 ; i <= n + week ; i++){
            ans += i;
        }
        return ans;
    }
}
