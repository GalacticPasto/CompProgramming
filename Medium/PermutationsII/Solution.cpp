#include <iostream>
#include <vector>
#include <algorithm>
class Solution{
    public:
        std::vector<std::vector<int>> permuteWithoutDuplicates(std::vector<int>& nums){
            std::vector<std::vector<int>> permutations;
            std::sort(nums.begin(), nums.end());
            generatePermutations(permutations,nums,0);
            for(std::vector<int> permu : permutations){
                for(int i : permu){
                    std::cout << i << " ";
                }
                std::cout << "\n" ;
            }
            return permutations;
        }
    private:
        void generatePermutations(std::vector<std::vector<int>>& permutations,std::vector<int>& nums,int i){
            if(i == nums.size()-1){
                permutations.push_back(nums);
            }
            for(int j = i ; j < nums.size(); j++){
                     
            }
        }

};

int main(){
    std::vector<int> nums = {1,1,2};
    Solution solu;
    solu.permuteWithoutDuplicates(nums);
}
