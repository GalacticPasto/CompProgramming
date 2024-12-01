#include <iostream>
#include <vector>

class Solution{
public:
    int findMin(std::vector<int>& nums){
        int low = 0;
        int high = nums.size() -1;
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low + high)/2;
            ans = std::min(nums[mid], ans);
            if(nums[low] <= nums[mid]){
                if(nums[mid] > nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            else{
                if(nums[mid] < nums[high]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
        }
        return ans;
    }
};

int main(){
    std::vector<int> a;
    int terminate = -1;
    int num;
    while((std::cin >> num) && num != terminate){
        a.push_back(num);
    }
    Solution solu;
    num = solu.findMin(a);
    for(int i : a){
        std::cout << i << " ";
    }
    std::cout << "\n";
    std::cout << num << "\n";
}
