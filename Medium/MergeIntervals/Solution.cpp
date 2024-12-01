#include <iostream>
#include <vector>

class Solution{
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals){
        int n = intervals.size();
        std::vector<std::vector<int>> ans;
        
        std::sort(intervals.begin(),intervals.end());
        
        int start = intervals[0][0];
        int end= intervals[0][1];

        for(int i = 1 ; i < n ; i++){
            if(intervals[i][0] <= end){
                end = std::max(intervals[i][1],end);
            } 
            else{
                ans.push_back({start,end});
                start = intervals[i][0];
                end= intervals[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};
