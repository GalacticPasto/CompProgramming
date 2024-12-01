#include <iostream>
#include <vector>

class Solution{
    public:
        int rob(std::vector<int>& nums){
            int n = nums.size();
            int dp[n];
            
            dp[0] = nums[0];
            dp[1] = std::max(nums[1],dp[0]);
            
            for(int i = 2 ; i < n-1; i ++){
                dp[i] = std::max(dp[i-1],dp[i-2]+nums[i]);
            }
            dp[0] = nums[0];
            dp[1] = nums[1]; 
            for(int i = 2 ; i < n ; i++){
            }
            return std::max(dp[n-1],dp[n-2]);
        }
};

int main(){
    Solution solu;
    std::vector<int> nums = {200,3,140,20,10};
    int ans = solu.rob(nums);
    std::cout << ans << " ";
}
