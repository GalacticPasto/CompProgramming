#include <iostream>
#include <vector>

class Solution {
    
public: 
    void nextPermutation(std::vector<int>& nums){
        int n = nums.size(); 
        int breakPoint = 0;
        bool flag = true;
        for(int i = n -2 ; i >= 0 ; i--){
            std::cout << i << "\n";
            for(int j = n-1; j > i ; j--){
                if(nums[j] > nums[i]){
                   breakPoint = i+1; 
                   std::swap(nums[i],nums[j]);
                   flag = false;
                   break;
                }
            }
           if(!flag)break;
        } 
        std::sort(nums.begin()+breakPoint,nums.end());
        for(int i : nums){
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
};

int main(){
    std::vector<int> nums ={1,2,3};
    Solution solu;
    solu.nextPermutation(nums);
}
