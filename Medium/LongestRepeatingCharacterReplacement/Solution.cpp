#include <iostream>

struct Solution{
    int characterReplacement(std::string s, int k){
        int max = 0;
        std::unordered_map<char,int> map; 
        int j = 0;
        int ans = 0;
        for(int i = 0 ; i < s.size() ; i++){
            map[s[i]]++;
            max = std::max(map[s[i]], max);
            if((i - j + 1)-max > k){
                map[s[j]]--;
                j++;
            }
            ans= std::max((i-j-1),ans);
        }
        return max;
    }
};

int main(){
    Solution solu;
    std::string s = "AABABBA";
    std::cout << solu.characterReplacement(s,1) << "\n";
}
