#include <vector>


int countNiceSubarrays(std::vector<int>& nums, int k){
    int ans = 0;    
    int left = 0;
    int count = 0;
    for(int i = 0 ; i < nums.size() ; i++){
        if(nums[i] % 2 != 0)count++;
        while(count > k){
            if(nums[left] % 2 != 0){
                count--;
            }
            left++;
        }
        ans += (i - left + 1);
    }
    return ans;
}

int numberOfSubarrays(std::vector<int>& nums, int k){
    return countNiceSubarrays(nums,k) - countNiceSubarrays(nums,k-1);
}
