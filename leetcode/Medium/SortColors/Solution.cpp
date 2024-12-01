#include <iostream>
#include <vector>

class Solution{
    public: 
        void sortColors(std::vector<int>& nums){
            printVector(nums);
            quickSort(nums,0,nums.size()-1);
            printVector(nums);
        }
        void sortColorsOn(std::vector<int>& nums){
            int n = nums.size();
            int i = 0;
            int j = 0;
            int k = n-1; 

            while(i < k){
                if(nums[i] == 0){
                    std::swap(nums[i],nums[j]); 
                    i++;
                    j++;
                }
                else if(nums[i] == 1){
                    i++;
                }
                else if(nums[i] == 2){
                    std::swap(nums[i], nums[k]);
                    k--;
                }
            }
        }
    private:
        void printVector(std::vector<int>& nums){
            for(int i : nums){
                std::cout << i << " ";
            }
            std::cout <<" " << std::endl;

        }
        void quickSort(std::vector<int>& nums,int low, int high){
            if(low <= high){
                int part = partition(nums,0 ,high); 
                
                quickSort(nums,0,part-1);
                quickSort(nums,part+1,high);
            }
        }
        int partition(std::vector<int>& nums, int low , int high){
            int pivot = nums[high];
            int i = low;
            int j = low;

            while(i <= high){
                if(nums[i] <= pivot){
                    int temp = nums[i];
                    nums[i]  = nums[j];
                    nums[j] = temp;
                    j++;
                }
                i++;
            }
            return j-1;
        }
};

int main(){
    std::vector<int> nums = {1,5,8,4,7,6,5,3,2};
    Solution solu;
    solu.sortColors(nums);
}
