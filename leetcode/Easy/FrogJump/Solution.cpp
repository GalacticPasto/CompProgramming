#include <iostream>
#include <vector>
#include <climits>
class Solution{
    public:
        int frogJump(int n, std::vector<int>& heights){
            std::vector<int> dp(n,-1);
            int energy = helper(heights,dp,n-1);
            return energy;
        }

        int helper(std::vector<int>& heights,std::vector<int>& dp, int indx){
            if(indx == 0){
                return 0;
            }
            if(dp[indx] != -1){
                return dp[indx];
            }
            int left = helper(heights,dp,indx-1) + std::abs(heights[indx] - heights[indx-1]);
            int right = INT_MAX;
            if(indx > 1){
                right = helper(heights,dp,indx-2) + std::abs(heights[indx] - heights[indx-2]);
            }
            dp[indx] = std::min(left,right);
            return dp[indx];
        }
};

int main(){
    std::vector <int> nums = {7,4,4,2,6,6,3,4};
    Solution solu;
    std::cout << solu.frogJump(nums.size(),nums);
}
