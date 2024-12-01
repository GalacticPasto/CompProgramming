#include <iostream>
#include <vector>

class Solution{
    public:
        void rotate(std::vector<std::vector<int>>& nums){
            transpose(nums);
            reverse(nums);
            display(nums);
            return;
        }
    private:
        void transpose(std::vector<std::vector<int>>& nums){
            for(int i = 0 ; i < nums.size() ; i++){
                for(int j = 0 ; j < nums[0].size() ; j++){
                    if(j > i){
                        std::swap(nums[i][j], nums[j][i]);
                    }
                }
            }
        }
        void reverse(std::vector<std::vector<int>>& nums){
            for(int i = 0 ; i < nums.size() ; i++){
                int left = 0;
                int right = nums[i].size()-1;
                while(left < right){
                    std::swap(nums[i][left] , nums[i][right]);
                    left++;
                    right--;
                } 
            }
        }
        void display(std::vector<std::vector<int>>& nums){
            for(std::vector<int> arr : nums){
                for(int i : arr){
                    std::cout << i << " ";
                }
                std::cout <<" \n";
            }
        }
};
int main(){
    std::vector<std::vector<int>> nums = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    Solution solu;
    solu.rotate(nums);
}
