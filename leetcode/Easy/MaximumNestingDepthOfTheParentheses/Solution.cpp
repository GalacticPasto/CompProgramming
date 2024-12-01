#include <iostream>
#include <vector>

class Solution{
public:
    int maxDepth(std::string s){
        int max = 0; 
        int open = 0;
        for(char c : s){
            if(c == '('){
                open++;
            }
            else if(c == ')'){
                max = std::max(open,max);
                open--;
            }
        }
        return max;
    }
};
