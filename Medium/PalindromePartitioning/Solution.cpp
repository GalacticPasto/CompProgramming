#include <iostream>
#include <vector>

class Solution{
    public:
        std::vector<std::vector<std::string>> partition(std::string s){
            std::vector<std::vector<std::string>> result;
            std::vector<std::vector<int>> dp(s.size(),std::vector<int>(s.size()));     

            for(int len = 1 ; len <= s.size() ; len++){
                for(int size = 0 ; size < s.size(); size++){
                    int j = len + size -1;
                    if(len == 1){
                        dp[size][size] = 1;
                    }
                    else if(len == 2){
                        dp[size][j] = (s[size] == s[j]);
                    }
                    else{
                        dp[size][j] = (s[size] == s[j] && dp[size][size+1] && dp[size][j-1]);
                    }
                }
            } 
            for(std::vector<int> res: dp){
               for(int st : res){
                   std::cout << st << " ";
               } 
               std::cout << "\n";
            }
               std::cout << "\n";
            for(int len = 1 ; len <= s.size() ; len++){
                std::vector<std::string> ans;
                bool flag = false;
                int count = 0;
                for(int size = 0 ; size < s.size(); size++){
                    int j = len + size - 1;
                    if(size == j){
                        ans.push_back(s.substr(size,len));
                    }
                    else if(dp[size][j] == 1 && flag == false){
                        ans.push_back(s.substr(size,len));
                        flag = true;
                        count = size;
                    }
                    else if(dp[size][j] == 1 && flag == true && size > len + count){
                        flag = false; 
                        count = 0;
                    }else if(dp[size][j] == 0){
                        for(int i = j-1; i < s.size() ; i++){
                            ans.push_back(s.substr(i,1));
                        } 
                    }
                }
                result.push_back(ans);
            } 
            for(std::vector<std::string> res : result){
                for(std::string st : res){
                    std::cout << st << " ";
                }
                std::cout << "\n";
            }
            return result;
        }
};
int main(){
    std::string s = "aaab";
    Solution solu;
    solu.partition(s);
}
