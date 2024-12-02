#include<iostream>
#include<algorithm>

long long largestPerimeter(std::vector<int>& nums){
    std::sort(nums.begin(), nums.end()); 
    long long ans = nums[0]; 
    int count = 0;    
    for(int i = 1 ; i < nums.size() ; i++){
        if(nums[i] <= ans){
            count++;
            ans+=nums[i];
        }
    }
    if(count < 3)return -1;
    return ans;
}

