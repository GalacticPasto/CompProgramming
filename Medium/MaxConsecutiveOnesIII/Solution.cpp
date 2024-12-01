#include <iostream>
#include <vector>

struct Solution{
public:
    int longestOnes(std::vector<int>& nums, int k){
        int max = 0;
        int right = 0,left = 0;
        int n = nums.size(); 
        
        while(right < n){
            if(nums[right] == 0)k--;
            if(k < 0){
                if(nums[left] == 0)k++;
                left++;
            }
            right++;
        }   
        return right - left;
    }


};

int main(){
    //std::vector<int> arr = {1,1,1,0,0,0,1,1,1,1,0};
    std::vector<int> arr = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    Solution solu;
    std::cout << solu.longestOnes(arr,3) << "\n";

}
