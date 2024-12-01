package BestTimeToBuySellStock;

public class Solution {

    public static void main(String[] args){
        int[] prices = {7,1,5,3,6,4};
        System.out.println(maxProfit(prices));
    }
    public static int maxProfit(int[] prices) {
        int buy = prices[0];
        int profit =0; 
        int maxProfit = 0;
        for(int i = 1 ; i < prices.length ; i++){
            profit =prices[i] - buy;
            if(buy > prices[i]){
                buy = prices[i];    
            }
            if(maxProfit < profit){
                maxProfit = profit;
            }
        }
        return maxProfit;
    }

}

