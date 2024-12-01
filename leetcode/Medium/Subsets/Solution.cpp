#include <iostream>
#include <vector>

class Solution{
            std::vector<std::vector<int>> result; 
    public:
        std::vector<std::vector<int>> subsets(std::vector<int>& nums){
            std::vector<int> set;
            result.push_back(set);
            result.push_back(nums);
           backTrack(nums,set,0); 
            return result;
        }
    private:
        void backTrack(std::vector<int>& nums, std::vector<int>& set,int indx){
            if(set.size()+1 == nums.size() || indx == nums.size()){
                result.push_back(set);    
                return;
            }
            set.push_back(nums[indx]);
            backTrack(nums,set,indx+1);
            set.pop_back();
            backTrack(nums,set,indx+1);
            return;
        }
};

int main(){
    std::vector<std::vector<int>> lol;
    Solution solu;
    std::vector<int> nums ={1,2,3,4};
    lol = solu.subsets(nums);
    for(std::vector<int> sets : lol){
        for(int i : sets){
            std::cout << i;
        }
        std::cout << " " << std::endl;
    }

}
