#include <iostream>
#include <vector>
#include <unordered_map>

class Solution{
public:
    bool isIsomorphicString(std::string s, std::string t){
        std::unordered_map<char,char> map; 
        
        for(int i = 0 ; i < s.size() ; i++){
            if(map.find(s[i]) == map.end()){
                map[s[i]] = t[i];
            }
            else{
                if(map[s[i]] != t[i])return false;
            }
            if(map.find(t[i]) == map.end()){
                map[t[i]] = s[i];
            }
            else{
                if(map[t[i]] != s[i])return false;
            }
            
        }
        return true;
    }
};

int main(){
    std::string s = "egg";
    std::string t = "goo";
    Solution solu;
    solu.isIsomorphicString(s,t);
}
