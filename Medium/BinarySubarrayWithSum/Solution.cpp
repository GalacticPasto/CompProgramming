#include <iostream>
#include <vector>

struct Solution{
    int count(std::vector<int>& nums, int goal){
        int count = 0;
        int sum= 0;
        int j = 0;
    
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
            if(sum > goal){
                sum -= nums[j++];
            }
            count += (i - j + 1); 
        }
        return count;
    }
    int numSubarrayWithSum(std::vector<int>& nums, int goal){
        return count(nums,goal) - count(nums,goal-1);
    }
};

