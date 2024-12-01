#include <iostream>
#include <vector>

class Solution{
<<<<<<< HEAD
    public:
        int combinationSum4(std::vector<int>& nums , int target){
            std::vector<int>dp(target+1,-1);
            dp[0] = 1;
            backTrack(nums,dp,target,0);
            return dp[target]; 
        }
    private:
        int backTrack(std::vector<int>& nums,std::vector<int>& dp, int target, int indx){
            if(indx == nums.size()){
                return 0;
            }
            int res = 0;
            for(int i = indx ; i < nums.size() ; i++){
                if(target == 0){
                    return 1;
                }
                if(target < 0){
                    return 0;
                }
                res += backTrack(nums,dp,target-nums[i],indx);
            }
            dp[target] = res;
            return res;
        }

=======
    int count = 0;
    public:
        int combinationSum4(std::vector<int>& nums, int target){
            backTrack(nums,target,0);
            return count;
        }
    private:
        void backTrack(std::vector<int>& nums, int target, int indx){
            if(indx == nums.size()){
                return;
            }
            for(int i = indx ; i < nums.size() ; i++){
                if(target == 0){
                    count++;
                    return;
                }
                if(target < 0)return;
                backTrack(nums,target-nums[i],indx);
            }
            return;
        }
>>>>>>> 17c12971aea15d7e3a2b5a5ce8c290f088aba456
};

int main(){
    std::vector<int> nums = {1,2,3};
    Solution solu;
<<<<<<< HEAD
    int count = solu.combinationSum4(nums,4);
    std::cout << count << "\n";
=======
    std::cout << solu.combinationSum4(nums,4) << "\n";
>>>>>>> 17c12971aea15d7e3a2b5a5ce8c290f088aba456
}
