#include <iostream>
#include<vector>

class Solution{
    public:
        int minCostClimbingStairs(std::vector<int>& cost){
            for(int i = 2 ; i < cost.size() ;i++){
                cost[i]+= std::min(cost[i-2],cost[i-1]);
            }
            return std::min(cost[cost.size()-1],cost[cost.size()-2]);
        }
};

