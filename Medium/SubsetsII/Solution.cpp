#include <iostream>
#include <vector>
#include <algorithm>
<<<<<<< HEAD

class Solution{
    public: 
        std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
            std::vector<std::vector<int>> subsets; 
            std::vector<int> subset;
            sort(nums.begin(), nums.end());
            generateSubsets(subsets,subset,nums,0);
            
=======
class Solution{
    public:
        std::vector<std::vector<int>> subsetsWithoutDuplicates(std::vector<int>& nums){
            std::vector<std::vector<int>> subsets;
            std::vector<int> subset;
            sort(nums.begin(),nums.end());
            generateSubsets(subsets,subset,nums,0);
>>>>>>> 17c12971aea15d7e3a2b5a5ce8c290f088aba456
            for(std::vector<int> sub : subsets){
                for(int i : sub){
                    std::cout << i << " ";
                }
                std::cout << "\n";
            }
<<<<<<< HEAD
            return subsets;
        }
        void generateSubsets(std::vector<std::vector<int>>& subsets, std::vector<int>& subset,std::vector<int>& nums, int indx){
            subsets.push_back(subset);
            for(int i = indx ; i < nums.size(); i++){
                if(i > indx && nums[i-1] == nums[i])continue;
=======
            return subsets;    
        }
    private:
        void generateSubsets(std::vector<std::vector<int>>& subsets,std::vector<int>& subset, std::vector<int>& nums,int indx){
            subsets.push_back(subset);
            for(int i = indx ; i < nums.size() ; i++){
                if(i > indx && nums[indx-1] == nums[indx])continue; 
>>>>>>> 17c12971aea15d7e3a2b5a5ce8c290f088aba456
                subset.push_back(nums[i]);
                generateSubsets(subsets,subset,nums,i+1);
                subset.pop_back();
            }
        }
<<<<<<< HEAD
};

int main(){
    std::vector<int> nums = {1,5,11,5}; 
    Solution solu;
    solu.subsetsWithDup(nums);
=======

};

int main(){
    std::vector<int> nums = {1,11,5,5};
    Solution solu;
    solu.subsetsWithoutDuplicates(nums);
>>>>>>> 17c12971aea15d7e3a2b5a5ce8c290f088aba456
}
