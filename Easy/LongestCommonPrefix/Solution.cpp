#include <iostream>
#include <vector>

class Solution{
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs){
        std::string commonPrefix = strs[0];
        for(int i = 1 ; i < strs.size() ; i++){
            for(int j = 0 ; j < strs[i].size() ; j++){
                if(commonPrefix[j] != strs[i][j]){
                    commonPrefix = commonPrefix.substr(0,j); 
                }
            }
            if(commonPrefix.size() > strs[i].size())commonPrefix = strs[i];
        }
        return commonPrefix;
    }
};

int main(){
    std::vector<std::string> strs = {"flower","flow","flight"};
    Solution solu;
    std::cout << solu.longestCommonPrefix(strs) << "\n";
}
