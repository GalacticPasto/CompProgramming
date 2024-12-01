#include <iostream>
#include <vector>

class Solution{
    public:
        int lengthOfLIS(std::vector<int>& nums){
            int length = 0;
            std::vector<int>dp(nums.size(),1);
            for(int i : dp){
                std::cout << i << " ";
            }
            std::cout << "\n";
            
            for(int i = 1 ; i < nums.size() ; i++){
                for(int j = 0 ; j < i ; j++){
                    if(nums[i] > nums[j]){
                        dp[i] = std::max(dp[j]+1,dp[i]);
                    }
                }
                length = std::max(dp[i], length);
            }
            return length;
        }
};

int main(){
    std::vector<int> nums = {0,1,0,3,2,3};
    Solution solu;
    int len = solu.lengthOfLIS(nums);
    std::cout << len << "\n";
}
