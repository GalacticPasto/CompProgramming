#include <iostream>
#include <vector>
#include <stack>
class Solution{
public:
    std::string removeOutermostParentheses(std::string& s){
        std::string ans;
        int open = 0;
        int close = 0;
        for(char c : s){
            if(c == '('){
                open++;
                if(open > 1){
                    ans.push_back('(');
                }
            }
            else{
                close++;
                if(close > 0 && open > 1){
                    ans.push_back(')');
                    open--;
                    close--;
                } 
                else{
                    open = 0;
                }
            }
        }
        return ans;
    }
};
int main(){
    std::string parentheses = "()()";
    Solution solu;
    std::cout << solu.removeOutermostParentheses(parentheses) << "\n";
}
