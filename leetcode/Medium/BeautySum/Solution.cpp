#include <iostream>
#include <vector>
#include <unordered_map>
class Solution{
public:
    int beautySum(std::string s){
        int beauty = 0;
       
        for(int i = 0 ; i < s.size() ; i++){
            std::unordered_map<char,int> map;
            for(int j = i ; j < s.size() ; j++){
                map[s[j]]++;
                int min = INT_MAX;
                int max = INT_MIN;
                for(std::unordered_map<char,int>::iterator it = map.begin(); it != map.end(); it++){
                    min = std::min(it->second,min);
                    max = std::max(it->second,max);
                } 
                beauty +=max-min;
            }
        }
        return beauty;
    }
};

int main(){
    std::string s = "aabcb";
    Solution solu;
    std::cout << solu.beautySum(s) << "\n";
}
