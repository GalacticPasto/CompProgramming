package CoinChange;

public class Solution {
    public static void main(String[] args){
        int[] coins = {1,2,5};
        System.out.println(coinChange(coins,11));
    } 
    private static int coinChange(int[] coins, int amount){
        int n = coins.length;
        int[] dp = new int[amount+1];
        
        for(int i = 1 ; i < dp.length ; i++){
            for(int coin : coins){
            }
        }

        return 0;
    }

}
