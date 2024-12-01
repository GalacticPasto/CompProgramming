#include <iostream>
#include <vector>
<<<<<<< HEAD
#include <unordered_map>
class Solution{
    public:
        int findNumberOfTls(std::vector<int>& nums){
            return 0;
=======
#include <algorithm>

class Solution{
    public:
        int findNumberOfLIS(std::vector<int>& nums){
            int n = nums.size();    
            if(n <= 1) return n;
            std::vector<int> dp(n,1),count(n,1);

            for(int i = 1 ; i < n ; i++){
                for(int j = 0 ; j < i ; j++){
                    if(nums[j] < nums[i]){
                        if(dp[j]+1 == dp[i]){
                            count[i] += count[j];
                        }
                        else{
                            dp[i] ++; 
                            count[i] = count[j];
                        }
                    }
                }
            }

            int longest = *std::max_element(dp.begin(), dp.end());
            int result = 0;    

            for(int i = 0 ; i < n ; i++){
                if(longest == dp[i] ) result += count[i];
            }
            return result;
>>>>>>> 17c12971aea15d7e3a2b5a5ce8c290f088aba456
        }
};

int main(){
<<<<<<< HEAD
    std::vector<int> nums = {1,2,4,3,5,4,7,2};
    Solution solu;
    std::cout << solu.findNumberOfTls(nums) << "\n";
=======
    std::vector<int> nums = {1,3,5,4,7};
    Solution solu;
    std::cout << solu.findNumberOfLIS(nums) << "\n";
>>>>>>> 17c12971aea15d7e3a2b5a5ce8c290f088aba456
}
