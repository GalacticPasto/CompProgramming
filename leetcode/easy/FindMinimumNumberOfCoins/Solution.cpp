#include <vector>

std::vector<int> minimumCoins(int n){
    int coins[10] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    std::vector<int> ans; 
    for(int i = 9-1 ; i >= 0 ; i--){
        while(n >= coins[i]){
                n -= coins[i];
                ans.push_back(coins[i]);
            }
    }
    return ans;
}

int main(){
    minimumCoins(13);
}
