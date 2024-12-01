#include <iostream>
#include <vector>

class Solution{
public : 
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int left = leftBound(nums,target);
        int right = rightBound(nums,target);
        return {left,right};     
    }
private:
    int leftBound(std::vector<int>& nums,int target){
        int low = 0;
        int high = nums.size()-1;
        int ans = 0;

        while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid] == target){
                ans = mid;
                high = mid -1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return ans;
    }
    int rightBound(std::vector<int>& nums,int target){
        int low = 0;
        int high = nums.size()-1;
        int ans = 0;

        while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid] == target){
                ans = mid;
                low = mid +1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return ans;
    }
};
int main(){
    std::vector<int> nums = {5,7,7,7,8,8,8,8,8,8,8,9,10};
    Solution solu;
    std::vector<int> ans = solu.searchRange(nums, 8);
    for(int i : ans){
        std::cout << i << std::endl;
    }
}
