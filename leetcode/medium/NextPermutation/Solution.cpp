#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
    public: 
        void nextPermutaion(std::vector<int>& nums){
            int n = nums.size();
            int i = n-2;  
            printArray(nums);
            while(i >= 0 && nums[i+1] <= nums[i]){
               i--; 
            }
            
            if(i >= 0){
                int j = n - 1;
                while(nums[i] >= nums[j]){
                    j--;
                }
                std::swap(nums[i],nums[j]);
            }
            std::reverse(nums.begin()+i+1, nums.end());
            printArray(nums);
        }
        void printArray(std::vector<int>& nums){
            for(int i : nums){
                std::cout << i << " ";
            }
            std::cout << ""<< std::endl;
        }


}; 
int main(){
    std::vector<int> nums = {1,5,8,4,7,6,5,3,1};
    Solution solu;
    solu.nextPermutaion(nums);
}
