#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

class Solution{
    public:
        std::vector<int> topKFrequentElemets(std::vector<int>& nums , int k){
            std::unordered_map<int,int> map; 
            for(int i = 0 ; i < nums.size();i++){
                map[nums[i]]++;
            }
            std::priority_queue<std::pair<int,int>> pq;
            for(std::unordered_map<int,int>::iterator it = map.begin(); it != map.end() ; it++){
                pq.push({it->second,it->first});
            }
            std::vector<int> ans;
            while(k--  && !pq.empty()){
                ans.push_back(pq.top().second); 
                pq.pop();
            }
            return ans;
        }
};

int main(){

}
