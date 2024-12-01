#include <iostream>
#include <vector>

class Solution{
    public:
        void printSubs(std::vector<int>& nums,int indx){
            std::vector<int> copy;
            helper(nums,copy,0);
            return;
        }
        void helper(std::vector<int>& nums, std::vector<int>& copy , int indx){
            if(indx == nums.size()){
                for(int i : copy){
                    std::cout << i << " ";
                }
                std::cout <<"\n";
                return;
            }
            copy.push_back(nums[indx]);
            helper(nums,copy,indx+1);
            copy.pop_back();
            helper(nums,copy,indx+1);
            return;
        }
};

int main(){
    std::vector<int> nums = {1,2,3};
    Solution solu;
    solu.printSubs(nums,0);
}
