#include <iostream>
#include <vector>

class Solution{
    public:
        int countSubStrings(std::string s){
            int n = s.size();
            if(n < 2)return 1;
            int dp[n+1][n+1];
            memset(dp,0,sizeof(dp)); 

            int count = s.size();
            for(int len = 1; len <= n ; len++){
                for(int i = 0 ; i <= n - len ; i++){
                    int j = i + len - 1;
                    dp[i][i] = 1;
                    if(s[i] == s[j] && dp[i+1][j-1]){
                        dp[i][j] = 1;
                        count++;
                    }
                }
            }
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    std::cout << dp[i][j] << " "; 
                }
                std::cout << "\n";
            }
            return count; 
        }
};

int main(){
    Solution solu;
    std::string s;
    std::cin >> s;
    std::cout << solu.countSubStrings(s) << "\n";
}
