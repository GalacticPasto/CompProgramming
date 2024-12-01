#include <iostream>
#include <vector>
#include <locale>

class Solution{
    public:
        std::vector<std::string> letterCasePermutation(std::string s){
            std::vector<std::string> result; 
            result.push_back(s);
            backTrack(result,s,0); 
            return result;
        }
    private:
        void backTrack(std::vector<std::string>& result, std::string& s , int indx){
            if(indx == s.size()){
                return;
            }
            for(int i = indx ; i < s.size() ; i++){
                if(std::isalpha(s[i])){
                    if(islower(s[i])){
                        s[i] = std::toupper(s[i]);
                        result.push_back(s);
                        backTrack(result,s,i+1);
                        s[i] = std::tolower(s[i]);
                    }
                    else{
                        s[i] = std::tolower(s[i]);
                        result.push_back(s);
                        backTrack(result,s,i+1);
                        s[i] = std::toupper(s[i]);
                    }
                }
            }
            return;
        } 
};

int main(){
    std::string st = "A1B2";
    std::vector<std::string> s;
    Solution solu;
    s = solu.letterCasePermutation(st); 
}
