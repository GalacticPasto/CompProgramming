#include <iostream>
#include <vector>
#include <unordered_map>

class Solution{
    public:
        std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs){
            std::vector<std::vector<std::string>> ans;
            std::unordered_map<std::string,std::vector<std::string>> map;
            
            for(std::string word :strs){
                std::string sorted = word;
                std::sort(sorted.begin(),sorted.end()); 
                map[sorted].push_back(word);
            }
            for(auto it = map.begin() ; it != map.end(); it++){
                ans.push_back(it->second);
            }
            return ans;
        }
};

int main(){
    std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
    Solution solu;
    std::vector<std::vector<std::string>> ans = solu.groupAnagrams(strs);
    for(std::vector<std::string> arr : ans){
        for(std::string word : arr){
            std::cout << word << " " ;
        }
        std::cout << "\n";
    }

}
