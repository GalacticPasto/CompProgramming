#include <iostream>
#include <vector>
#include <unordered_set>
<<<<<<< HEAD
class Solution{
    public:
        bool wordBreak(std::string s ,std::vector<std::string>& wordDict){
            int n = s.size();
            std::unordered_set<std::string> set; 

            int dp[n][n];
            memset(dp,0,sizeof(dp));

            for(std::string word : wordDict){
                set.insert(word);
            }
            
            for(int len = 1 ; len <= n ; len++){
                for(int i = 0 ; i <= n - len; i++){
                    int j = i + len - 1;
                    std::string sub = s.substr(i,len);
                    if(set.find(sub) != set.end()){
                        dp[i][j] = 1;
                    }
                    else{ 
                        bool flag = false;
                        for(int k = i ; k < j ; k++){
                            if(dp[i][k] && dp[k+1][j]){
                                flag = true;
                            }
                        }
                        dp[i][j] = flag;
                    }
                }
            }
            return dp[0][n-1];
        }

};

int main(){
    std::vector<std::string> wordDict = {"cats","dog","sand","and","cat"};
    Solution solu;
    bool flag = solu.wordBreak("catsandog",wordDict);
    std::cout << flag << "\n";
=======

class Solution {
 public:
    bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
        int n = s.size();
        bool table[n+1][n+1];
        std::unordered_set<std::string> dict;
        
        for(std::string s : wordDict){
            dict.insert(s);
        }

        for(int i = 1 ; i <= n ; i++){
            for(int j = 0 ; j <= n - i ; j++){
                int k = i + j;
                std::string sub = s.substr(j , k+1);
                std::cout << sub << std::endl;
            }
        }
        return false;
    }
};

int main() {
    std::vector<std::string> wordDict = {"my", "pen"};
    Solution solu;
    solu.wordBreak("mypen" , wordDict);
>>>>>>> 17c12971aea15d7e3a2b5a5ce8c290f088aba456
}
