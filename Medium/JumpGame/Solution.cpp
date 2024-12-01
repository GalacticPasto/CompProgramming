#include <iostream>
#include <vector> 

bool canJump(std::vector<int>& nums){
    int n = nums.size();
    int max = 0;
    for(int i = 0 ; i < n ; i++){
        if(max < i){
            return false;
        }
        std::max = (nums[i]+nums[i+nums[i]],max);
    }
    return max;
}


int main(){
    std::vector<int> nums = {3,2,1,0,4};
}
