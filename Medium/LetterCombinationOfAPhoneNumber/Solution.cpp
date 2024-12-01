#include <iostream>
#include <vector>
#include <unordered_map>

class Solution{

    std::unordered_map<int, std::string> map;    
    std::vector<std::string> combinations;
    public: 
        std::vector<std::string> letterCombination(std::string digits){

            fillSet(map);
            backTrack("",0,digits); 
            return combinations;
        }
        void backTrack(std::string tillNow ,int ptrForDigits,std::string& digits){
            if(ptrForDigits == digits.length()){
                combinations.push_back(tillNow);
                return;
            }
            char digit = digits[ptrForDigits];
            std::string letters = map[digit-'0'];
            for(char letter : letters){
                tillNow += letter;
                backTrack(tillNow,ptrForDigits+1,digits);
                tillNow.pop_back();
            }
        }
        void fillSet(std::unordered_map<int , std::string>& map){
            std::vector<std::string> letters = {
                 "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
            }; 

            for(int i = 2 ; i <= 9 ; i ++){
                map.insert({i, letters[i]});
            }
        }

};

int main(){
   Solution solu; 
   std::string digit = "23";
   std::vector<std::string> ans = solu.letterCombination("23");
   for(std::string st : ans){
        std::cout << st << std::endl;
   }
}
