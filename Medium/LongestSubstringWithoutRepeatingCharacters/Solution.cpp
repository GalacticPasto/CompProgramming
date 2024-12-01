#include <iostream>
#include <algorithm>
#include <unordered_set>
struct Solution{
public:
    int lengthOfLongestSubstring(std::string s){ //O(n^2)
        int n = s.size(); 
        int maxX = 0; 

        for(int i = 0 ; i < n ; i++){
            std::unordered_set<char> set;
            for(int j = i ; j < n ; j++){
                if(set.find(s[j]) != set.end()){
                    break;
                } 
                set.insert(s[j]);
            }
            int a = set.size();
            maxX = std::max(a,maxX);
        }
        return maxX;
    }
    int lengthOfLongestSubstringOptimized(std::string s){ 
        int n = s.size(); 
        std::unordered_set<char> set;
        int maxX = 0; 
        int left = 0;
        for(int i = 0 ; i < n ; i++){
            if(set.find(s[i]) != set.end()){
                while(set.find(s[i]) != set.end()){
                    set.erase(s[left]);
                    left++;
                }
            }
            set.insert(s[i]);
            maxX = std::max((i - left + 1),maxX);
        }
        return maxX;
    }
};

int main(){
    std::string s = "abcabcbb";
    Solution solu;
    std::cout << solu.lengthOfLongestSubstringOptimized(s) << "\n";
}
