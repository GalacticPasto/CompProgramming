#include <iostream>
#include <algorithm>
#include <stack>
class Solution{
public:
    std::string removeKDigits(std::string num, int k){
        std::stack<char> st;
        std::string ans = "";
        for(int i = 0 ; i < num.size(); i++){
            while(!st.empty() && k > 0 && st.top() > num[i]){
                k--;
                st.pop();
            }
            if(!st.empty() || num[i] != 0){
                st.push(num[i]);
            }
        }
        while(!st.empty() && k--){
            st.pop();
        }
        if(st.empty())return "0";
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        int i = ans.size()-1;
        while(ans[i--] == '0'){
            ans.pop_back();
        }
        std::reverse(ans.begin(),ans.end());
        return (ans == "") ? "0" : ans;
    }
};

int main(){
    Solution solu;
    std::string num = "10200";
    std::cout << solu.removeKDigits(num,1) << "\n";  
}
