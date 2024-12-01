#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
class Solution{
public:
    std::string frequncySort(std::string s){
        std::unordered_map<char,int> map;
        std::priority_queue<std::pair<int,char>> pQueue;
        
        for(char c : s){
            map[c]++;
        }
        for(std::unordered_map<char,int>::iterator it = map.begin() ; it != map.end() ; it++){
            pQueue.push({it->second,it->first});
        }
        std::string ans;
        while(!pQueue.empty()){
            std::pair temp = pQueue.top();
            int num = temp.first;
            while(num-- > 0){
                ans.push_back(temp.second);
            }
            pQueue.pop();
        }
        return ans;
    }
};
int main(){
    std::string s = "Aabb";
    Solution solu;
    std::cout << solu.frequncySort(s) << "\n";
}
