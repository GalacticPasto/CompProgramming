#include <iostream>
#include <vector>

class Solution{
    public:
        int maxAcendingSum(std::vector<int>& nums){
            int maxTillNow = 0;
            int maxMax = 0;
            for(int i = 1 ; i < nums.size();i++){
                if(nums[i] > nums[i-1]){
                    maxTillNow += nums[i-1];
                }
                else{
                    maxTillNow += nums[i-1];
                    maxMax = std::max(maxTillNow,maxMax);
                    maxTillNow = 0;
                }
            }
            maxTillNow += nums[nums.size()-1];
            maxMax = std::max(maxTillNow,maxMax);
            return maxMax;
        }
};

int main(){
    std::vector<int> nums = {10,20,30,40,50};
    Solution solu;
    int ans = solu.maxAcendingSum(nums);
    std::cout << ans << std::endl;
}
