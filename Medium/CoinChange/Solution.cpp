#include <iostream>
#include <vector>

class Solution{
    public:
<<<<<<< HEAD
        int coinChange(std::vector<int>& coins, int amount){
            int dp[coins.size()+1][amount+1];
            
            for(int i = 0 ; i <= coins.size(); i++){
                for(int j = 0 ; j <= amount ; j++){
                    if(i == 0){
                        dp[i][j] = 1e5;
                    }
                    else if(j == 0){
                        dp[i][j] = 0;
                    }
                    else if(coins[i-1] > j){
                        dp[i][j] = dp[i-1][j];
                    }
                    else{
                        dp[i][j] = std::min(dp[i-1][j], 1 + dp[i][j - coins[i-1]]);
                    }
                }
            }
            for(int i = 0 ; i <= coins.size(); i++){
                for(int j = 0 ; j <= amount ; j++){
                    std::cout << dp[i][j] << " ";
                }
                std::cout << "\n";
            }
            return (dp[coins.size()][amount] >= 1e5 ? -1 : dp[coins.size()][amount]);
        }
};

int main(){
    std::vector<int> coins = {1,2,5};
    Solution solu;
    solu.coinChange(coins,11);
}
=======
        int coinChange(std::vector<int>& coins , int amount){

            int n = coins.size();
            int dp[n][amount+1];
    
            for(int i = 0 ; i <= n ; i++){
                for(int j = 0 ; j <= amount ; j++){
                    if(j == 0){
                        dp[i][j] = 0;
                    }
                    else if(i == 0){
                        dp[i][j] = 1e5;
                    }
                    else if(coins[i] > j){
                        dp[i][j]  = dp[i-1][j];  
                    }
                    else{
                        dp[i][j] = std::min( 1 + dp[i][j-coins[i-1]] , dp[i-1][j]);
                    }
                }
            }
            return (dp[n][amount] > 1e5) ? -1 : dp[n][amount];
        }
};
>>>>>>> 17c12971aea15d7e3a2b5a5ce8c290f088aba456
