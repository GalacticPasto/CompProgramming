#include <iostream>
#include <stack>

class Solution{
public:
    std::string infixToPostfix(std::string exp){
        std::stack<char> st;
        std::string ans;
        for(char c : exp){
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
                ans.push_back(c);
            }
            else if(c == '('){
                st.push('(');
            }
            else if(c == ')'){
                while(st.top() != '('){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && orderOfOperation(c) >= orderOfOperation(st.top())){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(c);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }    
private:
    int orderOfOperation(char const operation){
        switch(operation){
            case '^':
                return 0;
            case '/' :
                return 1;
            case '*' :
                return 1;
            case '+' :
                return 2;
            case '-' :
                return 2;
        }
        return 3;
    }
};
int main(){
    Solution solu;
    std::string exp = "(p+q)*(m-n)";
    std::cout << solu.infixToPostfix(exp) << "\n";
}
