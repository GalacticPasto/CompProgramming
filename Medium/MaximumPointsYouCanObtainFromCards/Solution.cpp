#include <iostream>

int maxScore(std::vector<int>& nums, int k){
    int n = nums.size();
    int sum= 0;
    int left = 0;
    int right = n-1;
    
    while(left < n){
       if(nums[left] >= nums[right]){
            while(nums[left] >= nums[right] && k >= 0){
                if(nums[left] == nums[right])right--;
                sum += nums[left];
                left++;
                k--;
            }
       } 
       else{
            while(nums[right] > nums[left] && k >= 0){
                sum += nums[right];
                right++;
                k--;
            }
       }
    }
    return sum;
}

int main(){
    std::vector<int> vec = {9,7,7,9,7,7,9};
    std::cout << maxScore(vec,7) << "\n";

}
