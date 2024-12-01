#include <iostream>
#include <vector>
#include <unordered_set>

class Solution{
public:
    int countSubstrings(std::string str, int k){ // O(n^3) // O(n)
        int ans = 0;
        
        for(int len = 1 ; len < str.size(); len++){
            for(int i = 0 ; i <= str.size()-len; i++){
                if(countDifferentCharacters(str.substr(i,len))== k)ans++;
            }
        }
        if(countDifferentCharacters(str) == k)ans++;
        return ans;
    }
    int countSubstringsOptimized(std::string str, int k){
        int ans = 0;

        for(int i = 0 ; i < str.size(); i++){
            std::unordered_set<char> set;
            set.insert(str[i]);
            for(int j = i+1; j < str.size(); j++){
                set.insert(str[j]);
                if(set.size() == k)ans++;
            } 
            std::cout << "\n";
        }
        return ans;
    }
private:
    int countDifferentCharacters(std::string str){
        std::unordered_set<char> set;
        for(char c : str){
            set.insert(c);
        }
        return set.size();
    }

};

int main(){
    std::string str = "aacfssa";
    Solution solu;
    std::cout << solu.countSubstrings(str,3) << "\n";
    std::cout << solu.countSubstringsOptimized(str,3) << "\n";
}
