#include <iostream>
#include <vector>

class Solution{
    public:
        
        std::string longestPalindromicSubstring(std::string& s){
            




            return "";
        }
        std::string longestPalindromicSubstringDp(std::string& s){
            int n = s.size();
            int dp[n][n]; 
            memset(dp,0,sizeof(dp));
            std::string ans; 
            int length = 0;
            int endLen = 0;
            int size = 0;
            for(int i = 0 ; i < n ; i++){
                dp[i][i] = 1;
            }
            for(int i = 0 ; i < n -1 ; i++){
                if(s[i] == s[i+1]){
                    dp[i][i+1] = 1;
                    length = i;
                    endLen = 2;
                }
            }
            
            for(int i = 3 ; i <= n ; i ++){
                for(int j = 0 ;  j < n - i + 1 ; j++){
                    int k = i - 1 + j ;
                    if(s[j] == s[k] && dp[j+1][k-1]){
                        dp[j][k] = 1;
                        if(k > endLen){
                            length = j;
                            endLen = k;
                        }
                    }
                }
            }
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    std::cout << dp[i][j] << " ";
                }
                std::cout << "\n";
            } 
             
            return s.substr(length,endLen);
        }


};

int main(){
    std::string s = "aaabbcd";
    Solution solu;
    s = solu.longestPalindromicSubstring(s);
    std::cout << s << "\n";
}
