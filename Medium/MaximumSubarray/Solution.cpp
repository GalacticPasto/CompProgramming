#include <iostream>
#include <vector>

class Solution{
    public:
        int maxSubarray(std::vector<int>& nums){
            int maxSum = nums[0];
            int sum = nums[0];
            for(int i = 0 ; i < nums.size() ; i++){
                sum += nums[i];
                if(nums[i] > sum){
                    sum = nums[i];
                }
                if(sum > maxSum){
                    maxSum = sum;
                }
            } 
            return std::max(maxSum,sum);
        }
};

int main(){
    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution solu;
    int a =solu.maxSubarray(nums);
    std::cout << a << " ";
}
