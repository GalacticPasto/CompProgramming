#include <iostream>
#include <vector>

class Solution{
    public:
        std::vector<std::string> generateParentheses(int n){
            std::vector<std::string> ans;
            std::string str;
            generate(ans,str,n,0,0,0); 
            return ans;
        }
private:
        void generate(std::vector<std::string>& ans , std::string& str,int size,int indx,int open ,int close){
            if(str.size() == size * 2){
                ans.push_back(str);
                return;
            }
            if(open < size){
                str.push_back('(');
                open++;
                generate(ans,str,size,indx+1,open,close);
                str.erase(str.begin()+indx);
                open--;
            }
            if(close < open){
                str.push_back(')');
                close++;
                generate(ans,str,size,indx+1,open,close);
                str.erase(str.begin()+indx);
                close--;
            }
        }
};

int main(){
    Solution solu;
    solu.generateParentheses(3);
    int n;
    std::cin >> n;
    std::vector<std::string> ans = solu.generateParentheses(n);
    for(std::string res : ans){
        std::cout << res << "\n";
    }
}
