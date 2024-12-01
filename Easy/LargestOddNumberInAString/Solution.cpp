#include <iostream>
#include <vector>

class Solution{
public:
    std::string largestOddNumber(std::string num){
        std::string ans;

        for(int i = 0 ; i < num.size() ; i++){
            if(num[i] % 2 == 1){
                ans = num.substr(0,i);
            }
        }
        return ans;
    }
};
