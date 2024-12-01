#include<iostream>
#include<vector>

int rob(std::vector<int>& nums) {
    if(nums.size() < 2){
        return nums[0];
    }
    int dp[nums.size()];
    dp[0] = nums[0];
    dp[1] = std::max(dp[0],nums[1]);
    for(int i = 2 ; i < nums.size() ; i++){
        dp[i] = std::max(dp[i-1],(dp[i-2]+nums[i]));
    }
    return std::max(dp[nums.size()-1],dp[nums.size()-2]);
}

int main(){

}
