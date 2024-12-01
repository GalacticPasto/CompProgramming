#include <iostream>
#include <unordered_map>

int countNumberOfSubstrings(std::string s, int k) {
    int n = s.size();
    int ans = 0;
    int left = 0;
    std::unordered_map<char,int> map;
    for (int i = 0; i < n; i++) {
        map[s[i]]++;
        while(left < i && map.size() > k){
            map[s[left++]]--;
            if(map[s[left]] == 0)map.erase(s[left]);
            ans += i - left + 1;
        }
    }
    return ans;
}

int numberOfSubstrings(std::string s) {
    return countNumberOfSubstrings(s,3) - countNumberOfSubstrings(s,2);
}
