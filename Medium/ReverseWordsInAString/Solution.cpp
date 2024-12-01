#include <iostream>
#include <stack>
class Solution{
public:
    std::string reverseWords(std::string s){
        std::stack<std::string> stack;
        std::string word;
        
        for(char c : s){
            if(std::isdigit(c) || std::isalpha(c)){
                word.push_back(c);
            }
            else{
                if(!word.empty()){
                    stack.push(word);
                }
                word ="";
            }
        }
        stack.push(word);
        std::string ans = "";
        int size = stack.size();
        for(int i = 0 ; i < size ; i++){
            ans += stack.top() + " ";
            stack.pop();
        } 
        return ans;
    }
};

int main(){
    std::string word = "EPY2giL";
    Solution solu;
    std::cout << solu.reverseWords(word) << "\n";
    std::cout <<  '0'-0 << "\n";
    std::cout <<  '0'-9 << "\n";
}
