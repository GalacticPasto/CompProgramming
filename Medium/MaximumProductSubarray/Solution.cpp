#include <iostream>
#include <vector>

class Solution{
    public:
        int maxProduct(std::vector<int>& nums){
            int maxProduct = 0;
            int product = nums[0];
            for(int i = 1 ; i < nums.size() ; i++){
                product *= nums[i];
                maxProduct = std::max(product, maxProduct);
                if(product == 0){
                    product = 1;
                }
            }
            product = 1;
            for(int i = nums.size()-1 ; i >= 0 ; i--){
                product *= nums[i];
                maxProduct = std::max(product, maxProduct);
                if(product == 0){
                    product = 1;
                }
            }
            return maxProduct;
        }
};

int main(){
    std::vector<int> nums = {2,3,-2,4};
    Solution solu;
    int i = solu.maxProduct(nums);
    std::cout << i << "\n";
}
