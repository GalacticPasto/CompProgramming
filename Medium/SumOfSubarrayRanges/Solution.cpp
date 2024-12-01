#include <iostream>
#include <vector>

class Solution{
public:
    long long subarrayRanges(std::vector<int>& nums){
        int n = nums.size();
        long long ans = 0;
         
        for(int i = 0 ; i < n; i++){
            int min = nums[i];
            int max = nums[i];
            for(int j = i ; j < n ; j++){
                min = std::min(nums[j],min);
                max = std::max(nums[j],max);
                ans += max-min;
            }
        }
       return ans; 
    }
};
