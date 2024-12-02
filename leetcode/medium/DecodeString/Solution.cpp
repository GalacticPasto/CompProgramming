#include <iostream>
#include <unordered_set>
#include <vector>
#include <stack>
class Solution{
    public:
        std::string decodeString(std::string s){
            std::stack<char> st;
            
            for(int i = 0 ; i < s.size() ; i++){
                if(s[i] != ']'){
                    st.push(s[i]);
                }
                else{
                    std::string curr;

                    while(st.top() != '['){
                        curr = (st.top()) + curr;
                        st.pop();
                    }
                    
                    st.pop();
                    std::string number;
                    
                    while(!st.empty() && std::isdigit(st.top())){
                        number = st.top() + number;
                        st.pop();
                    }
                    int k = std::stoi(number); 
                    
                    while(k--){
                        for(int i = 0 ; i < curr.size() ;i++){
                            st.push(curr[i]);
                        }
                    }
                }
            }
            std::string ans = "";
            while(!st.empty()){
                ans = st.top() + ans;
                st.pop();
            }
            return ans;
        }
};
int main(){
    std::string s = "3[a]4[bc]";
    Solution solu;
    std::string ans = solu.decodeString(s);
    std::cout << ans << " ";
}
