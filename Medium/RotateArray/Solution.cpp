#include <iostream>
#include <vector>

class Solution{
    public:
        void rotate(std::vector<int>& nums, int k){
            int n = nums.size();
            std::vector<int> rotated(n);
            for(int i = 0 ; i < n ; i++){
                rotated[(i+k) % n] = nums[i];
            }
            nums = rotated;
        } 
};

int main(){
    std::vector<int> nums = {1,2,3,4,5,6,7};
    Solution solu;
    solu.rotate(nums,3);
}
